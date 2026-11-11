#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    bool flag=true;
    cin >> c1 >> s1 >> c2 >> s2;
    if ( c1!=c2 ){
        flag=false;
        cout << 0;
    }else cout << 1;
    if ( s1[0]==s2[0]&&s1[1]==s2[1] ) cout << 1;
    else {
        flag=false;
        cout << 0;
    }
    if ( s1[2]=='A' ) {
        if ( s2[2]=='B' ) {
            cout << 1;
        }else {
            flag=false;
            cout << 0;
        }
    }else if ( s1[2]=='B' ) {
        if ( s2[2]=='A' ) {
            cout << 1;
        }else {
            flag=false;
            cout << 0;
        }
    }else if ( s1[2]=='C' ) {
        if ( s2[2]=='D' ) {
            cout << 1;
        }else {
            flag=false;
            cout << 0;
        }
    }else if ( s1[2]=='D' ) {
        if ( s2[2]=='C' || s2[2]=='E' ) {
            cout << 1;
        }else {
            flag=false;
            cout << 0;
        }
    }else if ( s1[2]=='E' ) {
        if ( s2[2]=='D' ) {
            cout << 1;
        }else {
            flag=false;
            cout << 0;
        }
    }
    if ( flag ) cout << 0;
    else cout << 1;
    return 0;
}