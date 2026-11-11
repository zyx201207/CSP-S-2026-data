#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2)
    {
        cout << "0000" << endl;
        return 0;
    }
    cout << 1;
    int h1 = (s1[0] - '0') * 10 + (s1[1] - '0');
    int h2 = (s2[0] - '0') * 10 + (s2[1] - '0');
    if(h1 != h2)
    {
        cout << "000" << endl;
        return 0;
    }
    cout << 1;
    int z1 = s1[2] - 'A';
    int z2 = s2[2] - 'A';
    if((z1 <= 2 && z2 > 2) || (z1 > 2 && z2 <= 2))
    {
        cout << "00" << endl;
        return 0;
    }
    cout << 1;
    if(z1 <= 2 && z2 <= 2)
    {
        if(abs(z1 - z2) == 1) cout << 1;
        else cout << 0;
    }
    else cout << 1;
    cout << endl;
    return 0;
}
