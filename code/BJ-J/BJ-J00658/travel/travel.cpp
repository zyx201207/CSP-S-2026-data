#include <bits/stdc++.h>

using namespace std;
string c1,s1,c2,s2;
int ce(char c) { return (c == 'A' || c == 'B' || c == 'C') ? 1 : 2; }
bool xl(char a,char b)
{
    if(a == b - 1) return 1;
    if(a == 'D' && b == 'F') return 1;
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) cout << 1;
    else cout << 0;
    if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
    else cout << 0;
    if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && ce(s1[2]) == ce(s2[2])) cout << 1;
    else cout << 0;
    if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && ce(s1[2]) == ce(s2[2]) && xl(s1[2],s2[2])) cout << 1;
    else cout << 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
