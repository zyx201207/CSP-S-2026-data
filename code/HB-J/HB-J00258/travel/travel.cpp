#include <bits/stdc++.h>
using namespace std;

bool check(string a, string b)
{
    if (a[2] == 'A')
    {
        if ((b[2] == 'B') || (b[2] == 'C'))
            return true;
        return false;
    }
    if (a[2] == 'B')
    {
        if ((b[2] == 'A') || (b[2] == 'C'))
            return true;
        return false;
    }
    if (a[2] == 'C')
    {
        if ((b[2] == 'A') || (b[2] == 'B'))
            return true;
        return false;
    }
    if (a[2] == 'D')
    {
        if (b[2] == 'F')
            return true;
        return false;
    }
    if (a[2] == 'F')
    {
        if (b[2] == 'D')
            return true;
        return false;
    }
}

bool near(string a, string b)
{
    if (a[2] == 'A')
    {
        if (b[2] == 'B')
            return true;
        return false;
    }
    if (a[2] == 'B')
    {
        if ((b[2] == 'A') || (b[2] == 'C'))
            return true;
        return false;
    }
    if (a[2] == 'C')
    {
        if (b[2] == 'B')
            return true;
        return false;
    }
    if (a[2] == 'D')
    {
        if (b[2] == 'F')
            return true;
        return false;
    }
    if (a[2] == 'F')
    {
        if (b[2] == 'D')
            return true;
        return false;
    }
}

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int pai1 = 10 * (s1[0] - '0') + (s1[1] - '0');
    int pai2 = 10 * (s2[0] - '0') + (s2[1] - '0');

    if (c1 == c2) cout << 1;
    else cout << 0;

    if (c1 == c2 && pai1 == pai2) cout << 1;
    else cout << 0;

    if (c1 == c2 && pai1 == pai2)
    {
        if (check(s1, s2))
            cout << 1;
        else cout << 0;
    }
    else cout << 0;

    if (c1 == c2 && pai1 == pai2)
    {
        if (near(s1, s2))
            cout << 1;
        else cout << 0;
    }
    else cout << 0;
    return 0;
}
