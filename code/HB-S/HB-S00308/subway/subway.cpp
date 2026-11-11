#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[5005],t[505][5005],a[505][5005],k[505],vis[105],ans=1e9;
void dfs(int s,int e,int sum,int x,int op){
    if(s==e){
        ans=min(ans,sum+w[e]);
        return;
    }
    if(sum+w[e]>ans)return;
    if(op==1){
        for(int i=1;i<=k[x];i++){
            if(!vis[a[x][i]]){
                vis[a[x][i]]=1;
                dfs(a[x][i],e,sum+t[x][a[x][i]],x,0);
                vis[a[x][i]]=0;
            }
        }
    }else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==s){
                    vis[a[x][s]]=1;
                    dfs(s,e,sum+t[i][s],i,1);
                    vis[a[x][s]]=0;
                }
            }
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
            int x,y;
            cin>>x>>y;
            a[i][j]=x;
            t[i][a[i][j]]=y;
        }
    }
        for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            for(int ii=1;ii<=n;ii++){
                for(int j=1;j<=k[ii];j++){
                    if(a[ii][j]==x){
                        vis[a[ii][j]]=1;
                        dfs(x,y,w[x]+t[ii][x],ii,1);
                        vis[a[ii][j]]=0;
                    }
                }
            }
            cout<<ans<<endl;
            ans=1e9;
        }
    return 0;
}
