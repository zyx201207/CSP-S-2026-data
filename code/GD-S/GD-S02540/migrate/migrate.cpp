#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=6000;
const ll inf=1e18;
ll n,d;
ll c,T;
ll dp[N];
ll dis[N];
bool vis[N];
vector<int> e[N];
ll x[N];
ll g[N];
ll f[N];
ll ans=0;
deque <int>q;


void bfs(int x){
	memset(vis,0,sizeof(vis));
	memset(f,0,sizeof(f));
	for(int i=1;i<N;i++) dis[i]=inf;
	dis[x]=0;
	f[x]=1;
	vis[x]=1;
	q.push_back(x);
	while(!q.empty()){
		int p=q.front();
		q.pop_front();
		for(int i=0;i<e[p].size();i++){
			int k=e[p][i];
			if(dis[k]==dis[p]+1){
				f[k]+=f[p];
			}
			if(vis[k]) continue;
			vis[k]=1;
			dis[k]=dis[p]+1;
			q.push_back(k);
			f[k]+=f[p];
		}
	}
	return;
}


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	for(int o=1;o<=T;o++){
		for(int i=0;i<N;i++) e[i].clear();
		ans=0;
		memset(dp,0,sizeof(dp));
		memset(x,0,sizeof(x));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		x[n+1]=inf;
		for(int i=1;i<=n;i++){
			g[i]=i;
			int j=i+1;
			if(x[j]>x[i]+d) continue;
			for(j;j<=n;j++){
				e[i].push_back(j);
				if(x[j+1]>x[i]+d){
					g[i]=j;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			while(!q.empty()) q.pop_front();
			bfs(i);
			for(int j=i+1;j<=n;j++){
				if(f[j]==2) 
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
