#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2;
    string s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    char a = s1[2];
    char b = s2[2];
    bool f = 0;
    if((a == 'A' || a == 'B' || a == 'C') && (b == 'A' || b == 'B' || b == 'C')) f = 1;
    if((a == 'D' || a == 'F') && (b == 'D' || b == 'F')) f = 1;
    int d = abs(a-b);
    if(c1==c2) cout << 1;
    else cout << 0;
    if(c1==c2 && s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
    else cout << 0;
    if(c1==c2 && s1[0] == s2[0] && s1[1] == s2[1] && f ==1) cout <<1;
    else cout <<0;
    if(c1==c2 && s1[0] == s2[0] && s1[1] == s2[1] && f == 1 && d == 1) cout <<1;
    else cout << 0;
    return 0;
}
