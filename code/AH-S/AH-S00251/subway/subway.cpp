#include<iostream>
#include<vector>
using namespace std;
int c,n,m,d,q,w[500005],K,a[505][25],t[505][25],x,y;
bool e[505];
struct edge{
    int id,t;
};
vector<edge> g[505];
int dfs(int x,int y,int jz){
    if(x==y){
        return jz;
    }
    int minn=0x3f3f3f3f;
    for(int i=0;i<g[x].size();i++){
        int to=g[x][i].id;
        if(!e[x]){
            jz+=g[x][i].t;
            e[x]=1;
            minn=min(minn,dfs(to,y,jz));
            e[x]=0;
            jz-=g[x][i].t;
        }
    }
    return minn;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>K;
        for(int j=1;j<=K;j++){
            cin>>a[i][j]>>t[i][j];
            for(int l=1;l<=j-1;l++){
                g[a[i][j]].push_back({a[i][l],t[i][j]+t[i][l]});
                g[a[i][l]].push_back({a[i][j],t[i][j]+t[i][l]});
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        cout<<dfs(x,y,0)+w[x]+w[y]<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
