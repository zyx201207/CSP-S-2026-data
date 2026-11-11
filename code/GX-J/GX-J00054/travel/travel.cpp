#include <bits/stdc++.h>
using namespace std;

int same(string s1,string s2){
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
        if(s2[2]=='D' || s2[2]=='E'){
            return 1;
        }
    else if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
        if(s1[2]=='D' || s1[2]=='E'){
            return 1;
        }
    return 0;
}

int main(){
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2){
        cout << 1;
        if(c1[0]+c1[1]==c2[0]+c2[1]){
            cout << 1;
            if(same(s1,s2)){
                cout << 1;
                if(abs(s1[2]-s2[2])==1){
                    cout << 1;
                }else cout << 0;
            }else cout << 00;
        }else cout << 000;
    }else cout << 0000;
    return 0;
}
