#include<bits/stdc++.h>
using namespace std;

int n, m, mid, sum, ans;
long long a[500005], b[500005];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++)cin >> a[i];
    sort(a + 1, a + n + 1);
    mid = a[n / 2 + 1];
    for(int i=1; i<=n; i++)b[i] = abs(mid - a[i]);
    sort(b + 1, b + n + 1);
    for(int i=1; i<=n; i++)
    {
        if(sum + b[i] > m)break;
        sum += b[i], ans ++;
    }
    cout << ans;
    return 0;
}
