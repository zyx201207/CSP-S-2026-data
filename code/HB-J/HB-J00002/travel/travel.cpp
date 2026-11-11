#include<bits/stdc++.h>
using namespace std;

int main(){
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int ia,ib,sa,sb;
    if (s1[2]=='D' || s1[2]=='F') ia = 0;
    else ia = 1;
    if (s2[2]=='D' || s2[2]=='F') ib = 0;
    else ib = 1;
    if (s1[2]=='A') sa = 1;
    else if (s1[2]=='B') sa = 2;
    else if (s1[2]=='C') sa = 3;
    else if (s1[2]=='D') sa = 4;
    else sa = 5;
    if (s2[2]=='A') sb =1;
    else if (s2[2]=='B') sb = 2;
    else if (s2[2]=='C') sb = 3;
    else if (s2[2]=='D') sb = 4;
    else sb = 5;
    if (c1 == c2){
        cout << 1;
        if (s1[0]==s2[0] && s1[1]==s2[1]){
            cout << 1;
            if (ia == ib){
                cout << 1;
                if (sa==sb+1 || sa==sb-1) cout << 1;
                else cout << 0;
            }
            else cout << 0 << 0;
        }
        else cout << 0 << 0 << 0;
    }
    else cout << 0 << 0 << 0 << 0;
    return 0;
}
