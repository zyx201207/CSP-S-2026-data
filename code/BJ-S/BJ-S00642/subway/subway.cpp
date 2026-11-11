#include<bits/stdc++.h>
using namespace std;
int w[500005];
struct node{
    int id,val;
};
vector<node> p[500005];
long long f[505][505];
int ne[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(f,0x3f,sizeof(f));
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1,a,t,k;i<=n;i++){
        cin>>k;
        f[i][i]=0;
        while(k--){
            cin>>a>>t;
            p[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<p[i].size();j++){
            for(int k=j+1;k<p[i].size();k++){
                long long u=p[i][j].id,v=p[i][k].id,w=p[i][j].val+p[i][k].val;
                f[u][v]=min(f[u][v],w);
                f[v][u]=f[u][v];
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(i==k)continue;
            for(int j=i+1;j<=n;j++){
                if(j==k)continue;
                f[j][i]=f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        long long minn=0x3f3f3f3f3f3f3f3f;
        for(int i=0;i<p[x].size();i++){
            for(int j=0;j<p[y].size();j++){
                int u=p[x][i].id,v=p[y][j].id;long long w=p[x][i].val+p[y][j].val;
                minn=min(minn,f[u][v]+w);
            }
        }
        cout<<minn+w[x]+w[y]<<'\n';
    }
    return 0;
}