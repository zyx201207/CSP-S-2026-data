#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005];
long long lj[505][505];
vector<pair<int,long long> >v[500005];
vector<pair<int,long long> >g[505];
long long dis[505][505];
bool vis[505];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,b;
            cin>>a>>b;
            g[i].push_back({a,b});
            v[a].push_back({i,b});
        }
    }
    memset(lj,0x3f,sizeof lj);
    for(int i=1;i<=n;i++){
        for(auto j:g[i]){
            for(auto k:v[j.first]){
                if(k.first==i)continue;
                lj[i][k.first]=min(lj[i][k.first],j.second+k.second);
            }
        }
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++){
        priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >pq;
        dis[i][i]=0;
        memset(vis,0,sizeof vis);
        pq.push({0,i});
        while(!pq.empty()){
            pair<long long,int>tp=pq.top();
            pq.pop();
            if(vis[tp.second])continue;
            vis[tp.second]=1;
            for(int j=1;j<=n;j++){
                if(j==tp.second)continue;
                if(dis[i][j]>dis[i][tp.second]+lj[tp.second][j]){
                    dis[i][j]=tp.first+lj[tp.second][j];
                    pq.push({dis[i][j],j});
                }
            }
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        long long ans=0x3f3f3f3f3f3f3f3f;
        for(auto i:v[a]){
            for(auto j:v[b]){
                ans=min(ans,w[a]+w[b]+i.second+j.second+dis[i.first][j.first]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
