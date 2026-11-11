#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+6;
int n,m,a[N],s[N],ans=-1e18;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1,j=0;i<=n;i++){
        while(j<=n&&((j+1)-i+1)*a[j+1]-(s[j+1]-s[i-1])<=m)j++;
        if((j-i+1)*a[j]-(s[j]-s[i-1]))ans=max(ans,j-i+1);
    }
    cout << ans;
    return 0;
}
