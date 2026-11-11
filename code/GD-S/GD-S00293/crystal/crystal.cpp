#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 500005;
int a[maxn], sum[maxn];
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int st = 0, ans = 0;
    for(int i = 1;i <= n;i++){
        sum[i] = sum[i - 1] + a[i];
        while(sum[i] - sum[st] + m < (i - st) * a[i]) st++;
        ans = max(ans, i - st);
    }
    cout << ans;
    return 0;
}