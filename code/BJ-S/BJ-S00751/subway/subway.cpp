#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int c,n,m,d,q,w[500510],a,t,cnt,x,y,g[20500][20500];

void addEdge(int u,int v,int w){
    g[u][v]=w,g[v][u]=w;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    memset(g,0x3f,sizeof(g));

    cin>>c>>n>>m>>d>>q;

    for(int i=1;i<=m+n;i++) g[i][i]=0;

    for(int i=1;i<=m;i++) cin>>w[i];

    for(int i=1;i<=n;i++){
        cin>>c;
        for(int j=1;j<=c;j++){
            cin>>a>>t;
            addEdge(a,i+m,t);
        }
    }

    for(int i=1;i<=n+m;i++){
        for(int j=1;j<=n+m;j++){
            if(g[i][j]==0x3f3f3f3f) continue;
            for(int k=1;k<=n+m;k++){
                if(g[i][k]+g[i][j]<g[j][k]) g[k][j]=g[j][k]=g[i][k]+g[i][j];
            }
        }
    }

    while(q--){
        cin>>x>>y;
        cout<<w[x]+w[y]+g[x][y]<<endl;
    }
    return 0;
}
