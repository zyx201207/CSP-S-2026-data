#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef long long ll;
typedef pair<int,int> pii;
ll a[N];
vector<int>e[N];
int dis[N],cnt[N];
bool vis[N];
priority_queue<pii,vector<pii>,greater<pii> >pq;
void dd(int x){
    while(!pq.empty())pq.pop();
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    memset(cnt,0,sizeof cnt);
    cnt[x]=1;
    dis[x]=0;
    pq.push({0,x});
    while(!pq.empty()){
        int u=pq.top().second;pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto v:e[u]){
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                cnt[v]=cnt[u];
                pq.push({dis[v],v});
            }else if(dis[v]==dis[u]+1){
                cnt[v]+=cnt[u];
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--){
        ll n,d,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            e[i].clear();
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(abs(a[i]-a[j])<=d){
                    e[i].push_back(j);
                    e[j].push_back(i);
                }
            }
        }
        for(int i=1;i<=n;i++){
            dd(i);
            for(int j=i+1;j<=n;j++){
                if(i==j)continue;
                if(cnt[j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
