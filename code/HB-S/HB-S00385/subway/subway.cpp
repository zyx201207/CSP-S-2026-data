#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans;
int w[500005],k[505],a[505][500005],t[505][500005];
void dfs(int x,int tim){
    for(int i=1;i<=k[x];i++){
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=2*k[i];j++)
            cin>>a[i][j]>>t[i][j];
    }
    for(int i=1;i<=q;i++){
        ans=0;
        int x,y;
        cin>>x>>y;
        dfs(x,w[x]+w[y]);
        cout<<ans<<'\n';
    }
    return 0;
}
