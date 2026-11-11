#include <iostream>
#include <algorithm>
#include <cstdio>
#define ll long long
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a,b;
    string s1,s2;
    cin >> a >> s1 >> b >> s2;
    if (a == b) cout << 1;
    else
    {
        cout << "0000";
        return 0;
    }
    ll x = (s1[0]-'0') * 10 + (s1[1]-'0'),y = (s2[0]-'0') * 10 + (s2[1]-'0');
    if (x == y) cout << 1;
    else
    {
        cout << "000";
        return 0;
    }
    char c1 = s1[2],c2 = s2[2];
    if ('A' <= c1 && c1 <= 'C' && 'A' <= c2 && c2 <= 'C') cout << 1;
    else if ('D' <= c1 && c1 <= 'F' && 'D' <= c2 && c2 <= 'F') cout << 1;
    else
    {
        cout << "00";
        return 0;
    }
    if (c1 == 'A' && c2 == 'B' || c1 == 'B' && c2 == 'C' || c1 == 'B' && c2 == 'A' || c1 == 'C' && c2 == 'B') cout << 1;
    else if (c1 == 'D' && c2 == 'F' || c1 == 'F' && c2 == 'D') cout << 1;
    else cout << 0;
    return 0;
}
