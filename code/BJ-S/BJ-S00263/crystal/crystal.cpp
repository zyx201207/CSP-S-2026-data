#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
int n;
ll m, a[maxn];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) 
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = 1;
    ll cnt = 0;
    for(int i = 1, j = 1; i <= n; i ++) {
        if(i != 1) 
            cnt -= a[j] - a[i-1];
        while(j <= n && cnt <= m) 
            ++ j, cnt += (j - i) * (a[j] - a[j-1]);
        cnt -= (j - i) * (a[j] - a[j-1]);
        -- j;
        ans = max(ans, j - i + 1);
    }
    cout << ans << '\n';
    return 0;
}