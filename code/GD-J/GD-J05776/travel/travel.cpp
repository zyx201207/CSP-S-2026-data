#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b)
{
    if (a.size() != b.size())
        return 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c1, c2;
    string s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2)
    {
        cout << "0000\n";
        return 0;
    }
    else
        putchar('1');
    string pai1 = s1.substr(0, 2), pai2 = s2.substr(0, 2);
    if (cmp(pai1, pai2))
        putchar('1');
    else
    {
        cout << "000\n";
        return 0;
    }
    int lie1 = s1.substr(2)[0] - 'A', lie2 = s2.substr(2)[0] - 'A';
    if (lie1 <= 2 && lie2 <= 2)
        putchar('1');
    else if (lie1 > 2 && lie2 > 2)
    {
        cout << "11\n";
        return 0;
    }
    else
    {
        cout << "00\n";
        return 0;
    }
    if (abs(lie1 - lie2) > 1)
        cout << "0\n";
    else
        cout << "1\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}