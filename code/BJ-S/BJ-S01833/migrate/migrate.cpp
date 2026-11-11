#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100001];
int dis[100001];
vector<int> g[100001];
int b[1001][1001];
int n,m;
int astar(int x){
    int ans=0;
    memset(dis,0x3f,sizeof(dis));
    priority_queue<pair<int,int> >q;
    dis[x]=0;
    q.push({0,x});
    while(!q.empty()){
        int u=q.top().second;q.pop();
        b[x][u]++;
        for(auto v:g[u]){
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                q.push({-dis[v],v});
                b[x][v]=0;
            }
            else if(dis[v]==dis[u]+1){
                dis[v]=dis[u]+1;
                q.push({-dis[v],v});
            }
        }
    }
    for(int i=x+1;i<=n;i++){
        if(b[x][i]==2)ans++;
    }
    return ans;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=1;i<=100000;i++){
            g[i].clear();
        }
        cin>>n>>m;
        int ans1=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=m){
                    g[i].push_back(j);
                }
                else{
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++){
            ans1+=astar(i);
        }
        cout<<ans1<<"\n";
    }
}
