#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int n,m;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    int a[n+1];
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    int sum=0;
    int ans=1;
    for(int i=1;i<=n;i++){
        sum=sum+((a[i+1]-a[i])*i);
        if(sum<=m) ans++;
        else break;
    }
    cout << ans;
    return 0;
}
