#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=501;
int c,n,m,d,q,w[N],vis[M],a[N][M],ss[M][20],t[N][M];
long long min_=1e18;
void dfs(int st,int ed,int x,long long T){
    if(x==ed){
        min_=min(min_,T);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(a[x][i]&&vis[i]==0){
            for(int j=1;j<=ss[i][0];j++){
                if(x!=ss[i][j]){
                    vis[i]=1;
                    dfs(st,ed,ss[i][j],T+1ll*t[x][i]+1ll*t[ss[i][j]][i]);
                    vis[i]=0;
                }
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio();
    cin.tie();cout.tie();
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k,x,tt;
        cin>>k;
        ss[i][0]=k;
        for(int j=1;j<=k;j++){
            cin>>x>>tt;
            ss[i][j]=x;
            a[x][i]=1;
            t[x][i]=tt;
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        min_=1e18;
        dfs(x,y,x,0);
        cout<<min_+1ll*w[x]+1ll*w[y]<<"\n";
    }
    return 0;
}
