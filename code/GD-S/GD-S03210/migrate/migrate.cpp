#include<bits/stdc++.h>
#define int long long
#define rint register int
#define endl '\n'
using namespace std;
const int N=5e3+5;
vector<int> G[N];
int c,T;
int n,D;
int a[N];
int d[N];
int dis[N];
bitset<N> vis,e[N];
inline void bfs(const rint& s){
	vis.reset();
	for(rint i=1;i<=n;++i)
		d[i]=0,dis[i]=0;
		
	queue<int> q;
	q.push(s);
	dis[s]=0;
	vis[s]=1;
	d[s]=1;
	while(!q.empty()){
		rint u=q.front();q.pop();
		for(auto v:G[u]){
			if(!vis[v]) dis[v]=dis[u]+1,q.push(v),vis[v]=1;
			if(dis[v]==dis[u]+1) d[v]+=d[u];
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>T;
	
	while(T--){
		for(rint i=1;i<=n;++i)
			G[i].clear(),e[i].reset();
		
		cin>>n>>D;
		for(rint i=1;i<=n;++i){
			cin>>a[i];
		}
		for(rint i=1;i<=n;++i){
			rint pos=upper_bound(a+1,a+1+n,a[i]+D)-a-1;
			for(rint j=i+1;j<=pos;++j){
				if(!e[i][j])G[i].push_back(j),e[i][j]=1;
				if(!e[j][i])G[j].push_back(i),e[j][i]=1;
			}
				
		}
		
		rint ans=0;
		
		for(rint i=1;i<=n;++i){
			bfs(i);
			for(rint j=i+1;j<=n;++j){
				if(d[j]==2) ++ans;
			}
				
		}
		cout<<ans<<endl;
	}
	return 0;
}

