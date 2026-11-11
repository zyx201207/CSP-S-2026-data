#include<bits/stdc++.h>
#define vt vector
#define ll long long
#define x first
#define y second
#define PII pair<ll,ll>
#define pb push_back
#define lowbit(x) x&(-x)
using namespace std;
const int N=1e6+10;
const int INF=0x3f3f3f3f;
ll c,t,n,d,x[N],dis[N],cnt[N],ans;
bool vis[N];
struct node{
	ll v,w;
};
vt<node>g[N];
priority_queue<PII>q;
void dijkstra(ll st){
	dis[st]=0;
	cnt[st]=0;
	q.push({st,0});
	while(!q.empty()){
		ll u=q.top().x;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto ed:g[u]){
			ll v=ed.v,w=ed.w;
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				cnt[v]=1;
				q.push({v,dis[v]});
			}else if(dis[v]==dis[u]+1){
				cnt[v]=cnt[u]+1;
			}
		} 
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[i]-x[j])<=d){
					g[i].pb({j,1});
					g[j].pb({i,1});
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				vis[j]=cnt[j]=0;
				dis[j]=INF; 
			}
			dijkstra(i);
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl; 
	}
}

