#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000001],vis[1000001],ans;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],vis[i]=1;
    for(int i=40,c;i>=0;i--){
        c=0;
        for(int j=1;j<=n;j++)if(vis[j])c+=a[j]>>i&1;
        if(c>=m){
            ans|=1ll<<i;
            for(int j=1;j<=n;j++)vis[j]&=a[j]>>i&1;
        }
    }
    cout<<ans;
    return 0;
}
