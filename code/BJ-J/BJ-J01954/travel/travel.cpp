#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool check(){
    return (s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='E')||(s1[2]=='E'&&s2[2]=='D');
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2) cout << 1;
    else cout << 0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]) cout << 1;
    else cout << 0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))) cout << 1;
    else cout << 0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))&&check()) cout << 1;
    cout << 0;
    return 0;
}

