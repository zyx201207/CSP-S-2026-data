
#include<bits/stdc++.h>
using namespace std;
int main(){
    string c1,s1,c2,s2;
    int flag = 1;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << 1;
    }
    else{
        cout << 0;
        flag = 0;
    }
    if(s1[1] == s2[1] && s1[0] == s2[0] && flag == 1){
        cout << 1;
    }
    else{
        cout << 0;
        flag = 0;
    }
    char x = s1[2];
    char y = s2[2];
    if(flag == 1){
        if(x == 'A'){
            if(y == 'B'){
                cout << 1 << 1;
            }
            else if(y == 'C'){
                cout << 1 << 0;
            }
            else{
                cout << 0 << 0;
            }
        }
        else if(x == 'B'){
            if(y == 'A' || y == 'C'){
                cout << 1 << 1;
            }
            else{
                cout<< 0 << 0;
            }
        }
        else if(x == 'C'){
            if(y == 'B'){
                cout << 1 << 1;
            }
            else if(y == 'A'){
                cout << 1 << 0;
            }
            else{
                cout << 0 << 0;
            }
        }
        else if(x == 'D'){
            if(y == 'F'){
                cout << 1 << 1;
            }
            else{
                cout << 0 << 0;
            }
        }
        else if(x == 'F'){
            if(y == 'D'){
                cout << 1 << 1;
            }
            else{
                cout << 0 << 0;
            }
        }
    }
    return 0;
}
