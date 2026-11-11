#include<bits/stdc++.h>
using namespace std;
int a[200010], cnt[200010];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> a[i], cnt[a[i]] = max(cnt[a[i]], i);
    for(int i = 1; i <= m; i++)cout << cnt[i] << " ";
    cout << "\n";
    return 0;
}
