#include <bits/stdc++.h>
using namespace std;
int n, m, appear[300005];
bool date [300005];
void k(int i, string s)
{
    for (int j = 1;j <= m;j++)
    {
        if (date[j]) date[j] = 0;
    }
    string ss;
    for (int j = i + 1;j < n;j++)
        ss += s[j];
    int r = 1;
    while (r > 0)
    {
        char c = ss[0];
        int pos = 0;
        for (int k = 1;k < ss.length();k++)
        {
            if (ss[i] == ss[0])
            {
                pos = i;
                break;
            }
        }
        if (pos != 0)
            ss.erase(0, pos);
        else if (!date [c])
        {
            appear[c]++;
            date[c] = 1;
        }
        ss.erase(0, 1);
        r = ss.length();
    }
}
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    string s;
    cin >> n >> m;
    for (int i = 0;i < n;i++)
    {
        cin >> s[i];
    }
    for (int i = 0;i < n;i++)
        k(i, s);
    for (int i = 1;i <= m;i++)
        cout << appear[i] << " ";
    return 0;
}
