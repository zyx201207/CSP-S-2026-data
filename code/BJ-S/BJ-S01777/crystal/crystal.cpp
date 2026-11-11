#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],sum[500005];
int ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    int now = 1;
    for(int i = 1;i <= n;i++){
        sum[i] = sum[i - 1] + a[i];
        while(1ll * (i - now + 1) * a[i] - (sum[i] - sum[now - 1]) > m) now++;
        ans = max(ans,i - now + 1);
    }
    cout << ans;
    return 0;
}
