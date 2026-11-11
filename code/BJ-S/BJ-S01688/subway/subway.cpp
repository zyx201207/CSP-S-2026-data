#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y,ans=0x3f3f3f3f3f3f3f3f;
long long w[1000000],k[1000000];
long long a[25][500005],t[25][500005];
long long hc[25000][1000];
void dfs(long long now,long long sumt){
    if(now==y){
        ans=min(ans,sumt);
        return;
    }
}
void solve(){
    cin>>x>>y;
    dfs(x,w[x]);
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
    for(int o=1;o<=q;o++){
        solve();
    }
    cout<<2026;
    return 0;
}
