#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2, t1, t2;

void check(char x, char y)
{
    if (x == 'A' && y == 'B') cout << "11";
    else if (x == 'A' && y == 'C') cout << "10";
    else if (x == 'B' && y == 'A') cout << "11";
    else if (x == 'B' && y == 'C') cout << "11";
    else if (x == 'C' && y == 'A') cout << "10";
    else if (x == 'C' && y == 'B') cout << "11";
    else if (x == 'D' && y == 'F') cout << "11";
    else if (x == 'F' && y == 'D') cout << "11";
    else cout << "00";
    return ;
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) cout << 1;
    else
    {
        cout << "0000";
        return 0;
    }
    t1 = s1.substr(0, 2);
    t2 = s2.substr(0, 2);
    if (t1 == t2) cout << 1;
    else
    {
        cout << "000";
        return 0;
    }
    char a = s1[2], b = s2[2];
    check(a, b);
    return 0;
}
