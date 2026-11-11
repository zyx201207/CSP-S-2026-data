#include <bits/stdc++.h>
using namespace std;
int n, ans;
string s, m, q, f,l;
void hw(string x, string y)
{
    for (int i = 0;i < x.size();i++)
    {
        if (x[i] != y[i])
            ans++;
    }
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        int a;
        string b;
        cin >> a >> b;
        for (int j = 1;j <= a;j++)
            s += b;
    }
    for (int i = s.size() - 1;i >= 0;i--)
        m += s[i];
    if (m == s)
    {
        cout << 0;
        return 0;
    }
    else
    {
        for (int i = 0;i < s.size() / 2;i++)
            q += s[i];
        for (int i = q.size() - 1;i >= 0;i--)
            f += q[i];
        for (int i = s.size() / 2 + 1;i < s.size();i++)
            l += s[i];
        hw(f, l);
        cout << ans;
    }
    return 0;
}
