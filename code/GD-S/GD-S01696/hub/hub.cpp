#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
const int N=1e6+1,K=1e6+1;
int c,t,n,k,mx,ans,sum,a[K],b[K],fa[N],cnt[N],dis[N];
vector<int> to[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(y)]=find(x);
}
void dfs(int x){
	if(x>k){
		sum=0;
		for(int i=1;i<=n;i++){
			fa[i]=i;
			b[i]=0;
			cnt[i]=0;
		}
		for(int i=1;i<=k;i++){
			b[a[i]]=1;
		}
		for(int i=1;i<=k;i++){
			int u=a[i];
			for(int v:to[u]){
				if(b[v]){
					merge(u,v);
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(b[i]){
				cnt[find(i)]=1;
			}
		}
		for(int i=1;i<=n;i++){
			sum+=cnt[i];
		}
		if(sum>2) return;
		queue<int> q;
		for(int i=1;i<=n;i++){
			dis[i]=n;
		}
		for(int i=1;i<=k;i++){
			dis[a[i]]=0;
			q.push(a[i]);
		}
		while(q.size()){
			int u=q.front();
			q.pop();
			for(int v:to[u]){
				if(dis[u]+1<dis[v]){
					dis[v]=dis[u]+1;
					q.push(v);
				}
			}
		}
		mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,dis[i]);
		}
		ans=min(ans,mx);
		return;
	}
	for(int i=a[x-1]+1;i<=n;i++){
		a[x]=i;
		dfs(x+1);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c<=12||c>=15){
		while(t--){
			cin>>n>>k;
			ans=n;
			for(int i=1;i<=n;i++){
				to[i].clear();
			}
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
				to[u].push_back(v);
				to[v].push_back(u);
			}
			dfs(1);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
