#include<bits/stdc++.h>

using namespace std;

int c,n,m,d,q;
int u,v;
int w[500005];
int lst[505][500005];
int t[505][500005];
int dis[505][505];
vector<int> vec[1005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dis,0x3f,sizeof(dis));

    cin>>c>>n>>m>>d>>q;

    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,w;
            cin>>x>>w;
            lst[i][x]=1;
            t[i][x]=w;
            vec[x].push_back(i);
        }
    }

    for(int k=1;k<=m;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    dis[i][j]=0;
                    continue;
                }
                if(lst[i][k] && lst[j][k]){
                    dis[i][j]=min(dis[i][j],t[i][k]+t[j][k]);
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<'\n';
    }
    */
    while(q--){
        cin>>u>>v;
        int ans=0x3f3f3f3f;
        int s,e;
        for(int i=0;i<=vec[u].size();i++){
            for(int j=0;j<=vec[v].size();j++){
                if(dis[vec[u][i]][vec[v][j]]<ans){
                    ans=dis[vec[u][i]][vec[v][j]];
                    s=vec[u][i];
                    e=vec[v][j];
                }
            }
        }
        cout<<ans+w[u]+w[v]+t[s][u]+t[e][v]<<'\n';
    }
    return 0;
}
