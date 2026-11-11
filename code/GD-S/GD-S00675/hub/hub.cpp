#include<bits/stdc++.h>
using namespace std;
#define int long long
int dep[207],k,t,n,u,v,c,f[207],vis[207];
vector<int> a[207];
void dfs1(int u,int fa){
	for(auto v:a[u]){
		if(v==fa||(f[u]==0&&f[v]==1)) continue;
		if(f[v]==0) dep[v]=min(dep[v],dep[u]+1);
		dfs1(v,u);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		int ans=0x3f3f3f3f3f3f3f3f;
		cin>>n>>k;
		for(int i=1;i<=n;i++) a[i].clear();
		for(int i=1;i<n;i++){
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for(int i=(1ll<<k)-1;i<=(1ll<<n)-1;i++){
			if(__builtin_popcount(i)!=k) continue;
			memset(f,0,sizeof(f));
			int x=i,cnt=1;
			while(x>=2){
				f[cnt]=x%2;
				cnt++;
				x/=2;
			}
			f[cnt]=x%2;
			cnt=0;
			memset(vis,0,sizeof(vis));
			memset(dep,0x3f3f,sizeof(dep));
			bool flag=0;
			for(int i=1;i<=n;i++){
				if(f[i]==1) dep[i]=0;
			}
			for(int i=1;i<=n;i++){
				if(vis[i]==0&&f[i]==1){
					dfs1(i,0);
					cnt++;
					if(cnt>2){
						flag=1;
						break;
					}
				}
			}
			if(flag) continue;
			int s=0;
			for(int i=1;i<=n;i++){
				s=max(dep[i],s);
			}
			ans=min(ans,s);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
