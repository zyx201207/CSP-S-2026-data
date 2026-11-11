#include <bits/stdc++.h>
using namespace std;
const int M=1e3+5;
int c,n,m,d,q;
int w[M],s[M][M];
bool vis[M];

bool bfs(int x,int y,int ans){
    queue<int> q;
    for(int i=1;i<=m;i++){
        if((!vis[i])&&s[x][i]){
            q.push(i);
            vis[i]=1;
        }
    }
    while(!q.empty()){
        int f=q.front();
        if(bfs(f,y,s[x][f]))s[x][y]=min(s[x][y]==0?INT_MAX:s[x][y],s[x][f]+s[f][y]);
        q.pop();
    }
    return s[x][y]!=0;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","r",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int x[M],y[M];
        for(int j=1;j<=k;j++)cin>>x[j]>>y[j];
        for(int u=1;u<=k;u++)for(int v=u+1;v<=k;v++){
            if(!s[x[u]][x[v]])s[x[u]][x[v]]=y[u]+y[v];
            if(!s[x[v]][x[u]])s[x[v]][x[u]]=y[u]+y[v];
            s[x[u]][x[v]]=min(s[x[u]][x[v]],y[u]+y[v]);
            s[x[v]][x[u]]=min(s[x[v]][x[u]],y[u]+y[v]);
        }
    }
    //for(int i=1;i<=m;i++)for(int j=i+1;j<=m;j++)if(s[i][j])cout<<i<<' '<<j<<' '<<s[i][j]<<'\n';
    int q1[100005],q2[100005];
    for(int i=1;i<=q;i++)cin>>q1[i]>>q2[i];
    for(int i=1;i<=q;i++){
        for(int i=1;i<=m;i++)vis[i]=0;
        bfs(q1[i],q2[i],0);
        cout<<w[q1[i]]+w[q2[i]]+s[q1[i]][q2[i]]<<'\n';
    }
    return 0;
}

