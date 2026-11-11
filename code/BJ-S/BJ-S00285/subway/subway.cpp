#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,m,n,q,d;
ll w[505],k[505],a[505][20005],t[505][20005],r_x[2005],r_y[2005];
bool vis[505][20005];
ll ans=0;
void dfs(ll x,ll y){
    int i;
    for(i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            if(a[i][j]==x){
                ans+=t[i][j];
                goto poly;
            }
        }
    }
    poly:;
    for(int j=1;j<=k[i];j++){
        if(a[i][j]==y){
            ans+=t[i][j];
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>r_x[i]>>r_y[i];
        memset(vis,false,sizeof(vis));
        ans+=k[r_x[i]]+k[r_y[i]];
        dfs(r_x[i],r_y[i]);
        cout<<ans<<"\n";
    }
    return 0;
}
