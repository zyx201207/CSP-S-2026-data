#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
long long sum, cnt;
char c[200005];
string s;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
        sum += a[i];
        for (int j = 1; j <= a[i]; j++)
        {
            s += c[i];
        }
    }
    for (int i = 0, j = s.size() - 1; i <= j; i++, j--)
    {
        if (s[i] != s[j])
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}