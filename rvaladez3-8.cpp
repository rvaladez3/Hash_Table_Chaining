#include <iostream>
#include <string> //that is going to be used for the key
#include <list>

using namespace std;

int hashMod(int k, int m){
    return k % m;
}


void hashTable(list<int> table[], int v, int n,  char identifier){
    int key = hashMod(v,n);
    if (identifier == 'i'){ //checks to see if if character is 'i' to insert
        table[key].insert(table[key].begin(), v);
    }
    else if (identifier == 'd'){
        bool erase = false;
        auto d = table[key].begin();
        while (d != table[key].end()){
            if(*d == v){
                d = table[key].erase(d);

                cout << v <<":DELETED;\n";
                erase = true;
                break;
            }
            else{
                ++d;
            }
        }

        if (erase == false){
            cout << v << ":DELETE_FAILED;\n";
        }
    }
    else if (identifier == 'o'){
        for(int i = 0; i < n; i++){
            cout<< i << ":";
            for(auto o = table[i].begin(); o != table[i].end(); o++   ){
                cout << *o << "->";
            }
            cout << ";"<<endl;
        }
    }
    else if(identifier == 's'){
        int index = 0;
        bool match = false;
        auto s = table[key].begin();
        while(s != table[key].end()){
            if (*s == v){
                int keyFound = key;

                cout << v << ":FOUND_AT"<< keyFound <<','<<index<<";\n";
                match = true;
                break;
            }
            else {
                index++;
                ++s;
            }

        }
        if(match == false){
            cout << v << ":NOT_FOUND;\n";
        }

    }
    else if (identifier == 'e'){
        exit(0);
    }

}

/*int hashInsert(int** t, int k){
    int i = 0;
    int j;
    if (t[j] == NULL){
        t[j] = &k;
        return j;
    }
    else
        i = i+1;
            while(i != m){
                return 0;
            }

}

int hashSearch(int** t, int k){
    int i = 0;
    int j;
    if (t[j] == NULL){
        t[j] = &k;
        return j;
    }
    else
        i = i+1;
    while(i != m){
        return 0;
    }

}
*/

int main() {
    int n;
    cin >> n;
    list<int> table[n];
    string i;
    cin.ignore();
    while(true){
        getline(cin, i);
        int v;
        char identifier = i[0];
        i.erase(i.begin());
        if(identifier =='i' || identifier =='d' ||identifier =='s'  ){
            v = stoi(i);
        }
        else{
            v = 0;
        }
        hashTable(table,v,n,identifier);
    }


return 0;

}