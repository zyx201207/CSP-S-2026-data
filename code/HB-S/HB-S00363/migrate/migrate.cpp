#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,a[1000005],minn,mins;
void dfs(ll u,ll step,ll m){
    if(u>m) return;
    if(u==m){
        if(step==minn) mins++;
        else if(step<minn) minn=step,mins=1;
        return;
    }
    for(int i=u+1;i<=m&&a[u]+d>=a[i];i++) dfs(i,step+1,m);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ll ans=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int l=1;l<n;l++){
            for(int r=l+1;r<=n;r++){
                minn=1e18,mins=0;
                dfs(l,0,r);
                if(mins==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
