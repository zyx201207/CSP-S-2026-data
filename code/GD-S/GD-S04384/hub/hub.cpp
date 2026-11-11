#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N(818);
int c,t,n,k,ans(1e9);
int u[N],v[N],f[N],vis[N],dis[N],w[N];
vector<int>a;
vector<int>e[N];
queue<int>q;
int find(int x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
int calc(int x,int y){
	if(x==y) return 0;
	memset(w,0,sizeof w);
	while(q.size()) q.pop();
	q.push(x);
	while(q.size()){
		int u(q.front());
		q.pop();
		for(int v:e[u]){
			if(!w[v]){
				w[v]=w[u]+1;
				q.push(v);
			}
		}
	}
	return w[y];
}
void dfs(int x,int c){
	if(c==k or x>n){
		if(c!=k) return;
		for(int i=1;i<=n;++i) f[i]=i;
		for(int i=1;i<n;++i){
			if(vis[u[i]] and vis[v[i]]){
				int fx(find(u[i])),fy(find(v[i]));
				if(fx!=fy);
				f[fx]=fy;
			}
		}
		int cnt(0);
		for(int i=1;i<=n;++i) if(vis[i]) if(find(i)==i) cnt++;
		if(cnt<=2){
			int mx(-1);
			for(int i=1;i<=n;++i){
				int mn(1e9);
				for(int j=1;j<=n;++j) if(vis[j]) mn=min(calc(i,j),mn);
				mx=max(mx,mn);
			}
			ans=min(ans,mx);
		} 
		return;
	}
	vis[x]=1;
	dfs(x+1,c+1);
	vis[x]=0;
	dfs(x+1,c);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>t;
	for(;t--;ans=1e9){
		cin>>n>>k;
		for(int i=1;i<=n;++i) e[i].clear();
		for(int i=1;i<n;++i){
			cin>>u[i]>>v[i];
			e[u[i]].push_back(v[i]);
			e[v[i]].push_back(u[i]);
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
} 
