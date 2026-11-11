#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],pre[500010],ans;
signed main(){
    freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout),
    cin.tie(0)->sync_with_stdio(0),cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    for(int i=1,j=1;i<=n;i++){
        while(j<=i&&(i-j)*a[i]-(pre[i-1]-pre[j-1])>m)j++;
        ans=max(ans,i-j+1);
    }
    cout<<ans;
}