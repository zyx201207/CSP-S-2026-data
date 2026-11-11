#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool f1, f2, f3;
    f1  = (c1 == c2);
    cout << f1;
    f2 = f1 && (s1.substr(0, 2) == s2.substr(0, 2));
    cout << f2;
    f3 = f2 && ((s1[2]=='D'&&s2[2]=='E')||(s1[2]=='E'&&s2[2] == 'D')||((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')));
    cout << f3;
    cout << (f3 && abs(int(s1[2]-s2[2]))==1);
    return 0;
}
