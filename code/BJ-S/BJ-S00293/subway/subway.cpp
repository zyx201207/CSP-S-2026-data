#include<bits/stdc++.h>
using namespace std;
const int N=502;
const int M=500005;
vector<pair<int,int>> g[M];//把一座车站看成一个点，存储边
int w[M];//相当于点权
int a[N][M];
int t[N][M];
int dis[M];
bool vis[M];
int solve(int s,int d){
    queue<int> q;
    q.push(s);
    dis[s]=0;
    vis[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=1;
        for(pair<int,int> p:g[u]){
            int v=p.first;
            int wei=p.second;

            if((!dis[v] || dis[v]>dis[u]+wei) && !vis[v]){
               dis[v]=dis[u]+wei;
               q.push(v);
            }

        }
    }
    return dis[d]+w[s]+w[d];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);//开注释
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];//每站进站需要w[i]分钟
    }
    for(int i=1;i<=n;i++){//n条线路
        int k;//第i条线路有k座车站
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
            //车站编号a[i]，从站厅到站台需要t[i]分钟
        }
        for(int p=1;p<=k;p++){
            for(int q=i;q<=k;q++){
                if(p!=q){
                    g[a[i][p]].push_back({a[i][q],t[i][p]+t[i][q]});
                }
            }
        }//加入边
    }
    for(int i=1;i<=q;i++){
        int s,d;
        cin>>s>>d;
        cout<<solve(s,d)<<'\n';
    }
    return 0;
}
