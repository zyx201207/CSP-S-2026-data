#include <bits/stdc++.h>
using namespace std;
int n, a, sum;
char b;
string s, ss;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a >> b;
        for (int j = 0;j < a;j++)
        {
            s += b;
        }
    }
    for (int i = s.length();i >= 0;i--)
    {
        ss += s[i];
    }
    for (int i = 0;i < s.length();i++)
    {
        if (s[i] != ss[i]) sum++;
    }
    cout << sum / 2;
    return 0;
}
