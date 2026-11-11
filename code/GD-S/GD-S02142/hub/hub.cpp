#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+5;
const int inf=numeric_limits<int>::max();

signed main();
void solve();
int find(int);
void merge(int,int);

vector<int>g[maxn];
int DSU[maxn];
int dis[maxn];

signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
#ifndef local
	freopen("hub.in" ,"r",stdin ),
	freopen("hub.out","w",stdout);
#endif
	int c,t;cin>>c>>t;
	while(t--)solve();
	return 0;
}

void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v),g[v].push_back(u);
	}
	int ans=inf;
	for(int s=0;s<1<<n;s++){
		if(__builtin_popcount(s)!=k)continue;
		for(int i=1;i<=n;i++)DSU[i]=i;
		for(int u=1;u<=n;u++){
			if((s>>(u-1))&1){
				for(int v:g[u]){
					if((s>>(v-1))&1){
						merge(u,v);
					}
				}
			}
		}
		set<int>val;
		for(int i=1;i<=n;i++){
			if((s>>(i-1))&1)val.insert(find(i));
		}
		if(val.size()>2)continue;
		queue<int>q; 
		for(int i=1;i<=n;i++){
			if((s>>(i-1))&1){
				dis[i]=0;
				q.push(i);
			}
			else dis[i]=inf>>1;
		}
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int v:g[u]){
				if(dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;
					q.push(v);
				}
			}
		}
		int res=0;
		for(int i=1;i<=n;i++)res=max(res,dis[i]);
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
}

int find(int u){
	return DSU[u]==u?u:(DSU[u]=find(DSU[u]));
}

void merge(int u,int v){
	u=find(u),v=find(v);
	DSU[v]=u;
}
