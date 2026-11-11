#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],d[500005],sum,ans,k,x;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> a[i];
    sort (a+1,a+n+1);
    for (int i=1; i<=n; i++) d[i] = a[i]-a[i-1];
    k = n;
    for (int i=n; i>=1; i--){
        if (k==1) break;
        sum-=d[i+1]*(i-k+1),x-=d[i+1];
        while (k>1&&sum+x+d[k]<=m){
            k--,x+=d[k+1],sum+=x;
        }
        ans = max(ans,i-k+1);
    }
    cout << ans;
    return 0;
}