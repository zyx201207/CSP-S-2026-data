#include<bits/stdc++.h>
using namespace std;
const int N=505,M=3e5+5;
int c,n,m,d,q,w[M],a[N][M],t[N][M],dis[M],vis[M];
vector<int>v[M];
void bfs(){
    queue<int>que;
    que.push(a[1][1]);
    // vis[a[1][1]]=1;
    // dis[a[1][1]]=0;
    while(!que.empty()){
        int x=que.front();
        que.pop();
        vis[x]=1;
        for(int i=0;i<v[x].size();i++){
            for(int j=1;j<=a[v[x][i]][0];j++){
                if(vis[a[v[x][i]][j]])continue;
                dis[a[v[x][i]][j]]=dis[x]+1;
                que.push(a[v[x][i]][j]);
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
        cin>>a[i][0];
        for(int j=1;j<=a[i][0];j++){
            cin>>a[i][j]>>t[i][j];
            // v[i][a[i][j]]=1;
            v[a[i][j]].push_back(i);
        }
    }
    // for(int i=1;i<=n;i++)for(int j=1;j<=a[i][0];j++)for(int k=1;k<=n;k++)if(k!=i)if(v[i][a[i][j]]&&v[k][a[i][j]])hc[i][k]=a[i][j];
    // for(int i=1;i<=m;i++){
    //     cout<<i<<':';
    //     for(int j=0;j<v[i].size();j++)cout<<v[i][j]<<' ';
    //     cout<<'\n';
    // }
    bfs();
    if(12<=c&&c<=19){
        int T=t[1][1];
        for(int q1=1,x,y;q1<=q;q1++){
            cin>>x>>y;
            cout<<(dis[y]-dis[x])*T+w[x]+w[y]<<'\n';
        }return 0;
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+t[1][1]<<'\n';
    }
    // for(int i=1;i<=m;i++)cout<<dis[i]<<' ';
    return 0;
}