#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int N=2000005;
const ll INF=0x3f3f3f3f3f3f3f3f;
vector<pll> G[N];
int n,d;
ll x[N];
ll dist[N];
bool vis[N];
int cnt=0;
int start=0;
int goal=0;
ll ans=0;
void dfs(int r,int cur){
	vis[r]=1;
	if(cnt>2||cur>dist[goal])return;
	if(r==goal&&cur==dist[goal]){
		cnt++;
		return;
	}
	for(auto e:G[r]){
		int v=e.first;
		if(vis[v]==0){
			vis[v]=1;
			cur++;
			dfs(v,cur);
			cur--;
			vis[v]=0;
		}
	}
}
void dj(int start){
	priority_queue<pll,vector<pll>,greater<pll> > qq;
	dist[start]=0;
	qq.push(make_pair(0,start));
	while(!qq.empty()){
		int d=qq.top().first;
		int u=qq.top().second;
		qq.pop();
		if(d>dist[u])continue;
		for(auto e:G[u]){
			int nd=e.second;
			int v=e.first;
			if(dist[v]>dist[u]+nd){
				dist[v]=dist[u]+nd;
			    qq.push(make_pair(dist[v],v));
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					int dd=x[j]-x[i];
					G[i].push_back(make_pair(j,dd));
					G[j].push_back(make_pair(i,dd));
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=n;j++)dist[j]=INF;
			dj(i);
			for(int j=i+1;j<=n;j++){
				cnt=0;
				start=i;
				goal=j;
				if(dist[j]==-1||x[j]-x[i]<=d)continue;
				memset(vis,0,sizeof(vis));
				dfs(i,0);
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
