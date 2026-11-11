#include <bits/stdc++.h>
using namespace std;
long long n;
long long m;
int ans = 0;
vector<long long> a(500005), sum(500005), j(500005);
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a.begin() + 1, a.begin() + n + 1);
    for(int i = 1;i < n;i++)
    {
        j[i] = a[i + 1] - a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        sum[i] = sum[i - 1] + i * j[i];
    }
    for(int i = 0;i <= n;i++)
    {
        int k = lower_bound(sum.begin() + i, sum.begin() + n + 1, m + 1) - sum.begin() - 1;
        ans = max(ans, k - i + 1);
        for(int l = i + 1;l <= n;l++)
        {
            sum[l] = sum[l - 1] + l * j[l];
        }
        //cout << k << endl;
    }
    cout << ans << endl;
    return 0;
}
