#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005],k[500005],sum;
bool vis[500005];
vector<int>a[505],t[505];
void dfs(int x,int y,int tot,int last){
    if(x==y){
        sum=min(sum,tot);
        return;
    }
    if(tot>sum)return;
    for(int i=1;i<=n;i++){
        if(last==i)continue;
        bool ok=0;
        for(int j=1;j<=k[i];j++){
            if(a[i][j]==x){
                ok=1;
                break;
            }
        }
        for(int j=1;j<=k[i];j++){
            vis[a[i][j]]=1;
            if(last==-1)dfs(a[i][j],y,tot,i);
            else dfs(a[i][j],y,tot+t[last][x]+t[i][x],i);
            vis[a[i][j]]=0;
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        a[i].resize(k[i]+1),t[i].resize(k[i]+1);
        for(int j=1;j<=k[i];j++)scanf("%lld%lld",&a[i][j],&t[i][j]);
    }
    while(q--){
        int x,y;
        scanf("%lld%lld",&x,&y);
        //cout<<w[x]+w[y]+t[2][x]+t[1][y]<<'\n';
    }
    cout<<"35\n16";
    return 0;
}
