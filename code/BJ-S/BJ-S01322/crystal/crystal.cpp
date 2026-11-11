#include <bits/stdc++.h>
using namespace std;
long long a[500005], b[500005], temp, m;
int n, ans;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++) b[i] += a[i] - a[i - 1] + b[i - 1];
    queue <int> q;
    int l = 1;
    for (int i = 1; i <= n; i++)
    {
        temp += (b[i] - b[i - 1]) * (i - l);
        q.push(1);
        while (temp > m && !q.empty())
        {
            l++;
            q.pop();
            temp -= (b[i] - b[l - 1]);
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans << endl;
    return 0;
}