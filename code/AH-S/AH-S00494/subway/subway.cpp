#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<cstring>
using namespace std;
vector<pair<int,int> >g[51];
map<int,int>ma[51],mb[51];
int c,n,m,d,q,w[51],f[51][21][51][21],b[51];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=m;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int x,y;
            scanf("%d%d",&x,&y);
            b[x]++;
            ma[x][i]=y;
            mb[x][b[x]]=i;
            f[x][i][x][i]=0;
            g[i].push_back({x,y});
        }
    }
    for(int i=1;i<=m;i++){
        int sz=g[i].size();
        for(int j=0;j<sz;j++){
            for(int k=0;k<sz;k++){
                int u=g[i][j].first,v=g[i][k].first;
                f[u][i][v][i]=f[v][i][u][i]=min(f[u][i][v][i],g[i][j].second+g[i][k].second);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=b[i];j++){
            for(int k=1;k<=b[i];k++){
                f[i][mb[i][j]][i][mb[i][k]]=f[i][mb[i][k]][i][mb[i][j]]=0;
            }
        }
    }
    for(int t=1;t<=n;t++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=b[i];k++){
                    for(int l=1;l<=b[j];l++){
                        for(int o=1;o<=b[t];o++){
                            f[i][mb[i][k]][j][mb[j][l]]=f[j][mb[j][l]][i][mb[i][k]]=min(f[i][mb[i][k]][j][mb[j][l]],f[i][mb[i][k]][t][mb[t][o]]+f[t][mb[t][o]][j][mb[j][l]]);
                        }
                    }
                }
            }
        }
    }
    while(q--){
        int u,v,ans=0x3f3f3f3f;
        scanf("%d%d",&u,&v);
        for(int i=1;i<=b[u];i++){
            for(int j=1;j<=b[v];j++){
                if(f[u][mb[u][i]][v][mb[v][j]]<ans){
                    ans=f[u][mb[u][i]][v][mb[v][j]];
                }
            }
        }
        printf("%d\n",ans+w[u]+w[v]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
