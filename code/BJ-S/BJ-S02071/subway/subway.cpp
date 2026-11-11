#include<bits/stdc++.h>
#define maxm 500005
#define maxn 505
#define ll long long
using namespace std;
int c,n,m,d,q;
int w[maxm];
int a[maxn][maxm],t[maxn][maxm];
bool vis[maxm];
int fa[maxm],counter=1;/**/
vector<int> g[maxm];
/*
0 2 5 20 2
2 4 1 9 2 5
3 3 1 5 2 7 4 6
4 3 2 3 3 4 5 7
5 1 3
6 1 2
*/
inline void bfs(int beg,int fin){
    ll sum=0;
    memset(vis,0,sizeof(vis));
    queue<ll> q;
    q.push(beg);
    vis[beg]=1;
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            if(!vis[v]){
                q.push(v);
                vis[v]=1;

            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
            fa[a[i][j]]=counter;
        }
        for(int j=2;j<=k;j++){
            g[a[i][j]].push_back(a[i][j-1]);
            g[a[i][j-1]].push_back(a[i][j]);
        }
        counter++;
    }
    /*
    for(int i=1;i<=m;i++){
        for(int j=0;j<g[i].size();j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    //for(int i=1;i<=m;i++)cout<<fa[i]<<" ";
    while(q--){
        int start,ending;
        cin>>start>>ending;
        ll ans=w[start]+w[ending];
        //bfs(start,ending);
        cout<<ans;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
