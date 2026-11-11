#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<cmath>
#define int long long
#define P pair<long long,long long>
using namespace std;
struct edge{
    int next,w;
};
int c,n,m,d,q1,t;
vector<edge> g[5005];
int cnt[5005];
int dis[5005];
int w[5005];
priority_queue<P,vector<P>,greater<P> > q;
void Dij(int st){
    while(!q.empty())q.pop();
    memset(dis,0x3f,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    q.push({0,st});
    dis[st]=0;
    cnt[st]=1;
    while(!q.empty()){
        P tmp=q.top();q.pop();
        if(tmp.first>dis[tmp.second])continue;
        int u=tmp.second;
      //  cout<<st<<" "<<u<<" "<<cnt[u]<<endl;
        for(int i=0;i<g[u].size();i++){
            edge v=g[u][i];
            if(dis[u]+v.w<dis[v.next]){
                dis[v.next]=dis[u]+v.w;
                cnt[v.next]=cnt[u];
                q.push({dis[v.next],v.next});
            }else if(dis[u]+v.w==dis[v.next])cnt[v.next]+=cnt[u];
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int sum=0;
        cin>>n>>d;
        n++;
        for(int i=1;i^n;i++){
            scanf("%lld",&w[i]);
            g[i].clear();
        }
        for(int i=1;i^(n-1);i++){
            for(int j=i+1;j^n;j++){
                if(abs(w[i]-w[j])<=d){
                    g[i].push_back({j,1});
                    g[j].push_back({i,1});
                }
            }
        }
        for(int i=1;i^(n-1);i++){
            Dij(i);
            for(int j=i+1;j^n;j++){
      //          cout<<i<<" "<<j<<" "<<cnt[j]<<"\n";
                if(cnt[j]==2)sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
