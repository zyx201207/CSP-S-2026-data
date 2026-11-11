#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c1, s1;
    string c2, s2;
    cin >> c1 >> c2 >> s1 >> s2;
    int c3 = (c2[0]- '0')* 10 + c2[1] - '0';
    int s3 = (s2[0]- '0')* 10 + s2[1] - '0';
    if (c1 != s1)
    {
        cout << "0000";
        return 0;
    }
    cout << 1;
    if (c3 != s3)
    {
        cout << "000";
        return 0;
    }
    cout << 1;
    if (s2[2] == 'C')
        swap(s2[2], c2[2]);
    if (c2[2] == 'C' && s2[2] == 'D')
    {
        cout << "00";
        return 0;
    }
    if (c2[2] == 'C' && s2[2] == 'A')
    {
        cout << "10";
        return 0;
    }
    if (abs(c2[2]- s2[2]) == 1)
    {
        cout << "11";
        return 0;
    }
    cout << "00";
    return 0;
}
