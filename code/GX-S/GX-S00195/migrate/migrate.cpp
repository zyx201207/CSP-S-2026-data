#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int N=5e3+10,INF=0x3f3f3f3f;
int c,t,n;
ll f,x[N],ans;
int dis[N],ts[N];
vector<vector<int>> g(N);
ll djl(int s){
    ll res=0;
    priority_queue<pii,vector<pii>,greater<pii>> p;
    fill(dis+1,dis+n+1,INF);
    fill(ts+1,ts+n+1,0);
    dis[s]=0;
    p.push({0,s});
    while(!p.empty()){
        int d=p.top().first,u=p.top().second;
        p.pop();
        if(d>dis[u])continue;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            if(d+1<dis[v]){
                dis[v]=d+1;
                if(v>s){ts[v]++;}
                p.push({dis[v],v});
            }
            else if(d+1==dis[v]&&v>s){ts[v]++;}
        }
    }
    for(int i=s+1;i<=n;i++){if(ts[i]==2)res++;}
    return res;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>f;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]<=f)g[i].push_back(j);
                else break;
            }
        }
        for(int i=1;i<n;i++){
            ans=ans+djl(i);
        }
        cout<<ans<<endl;
    }
    return 0;
}
