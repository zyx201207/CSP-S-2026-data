#include<bits/stdc++.h>
#define PII pair<int,int>
#define fi first
#define se second
#define int long long
using namespace std;
int c,T,n,k,f[1000010],vis[1000010];
vector <int> g[1000010];
int findset(int x){
	if(f[x]==x) return f[x];
	return f[x]=findset(f[x]);
}
struct info{
	int a,b;
}ed[1000010];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			ed[i]={u,v};
		}
		if(c<=3){
			for(int i=1;i<=n;i++){
				f[i]=i;
			}
			int ans=1e18;
			for(int i=0;i<(1ll<<n);i++){
				int ct=0;
				for(int j=1;j<=n;j++){
					f[j]=j;
					if(i&(1ll<<(j-1))){
						ct++;
					}
				}
				if(ct!=k) continue;
				for(int j=1;j<n;j++){
					int u=ed[j].a,v=ed[j].b;
					if((i&(1ll<<(u-1)))&&(i&(1ll<<(v-1)))){
						int fx=findset(u),fy=findset(v);
						if(fx!=fy){
							f[fx]=fy;
							ct--;
						}
					}
				}
				if(ct>2) continue;
				queue <PII> q;
				int res=0;
				for(int j=1;j<=n;j++){
					vis[j]=0;
					if(i&(1ll<<(j-1))){
						q.push({j,0});
						vis[j]=1;
					}
				}
				while(!q.empty()){
					int x=q.front().fi;
					res=max(res,q.front().se);int t=q.front().se;
					q.pop();
					for(auto y:g[x]){
						if(vis[y]) continue;
						vis[y]=1;
						q.push({y,t+1});
					}
				}
				ans=min(ans,res);
			}
			cout<<ans<<'\n';
			for(int i=1;i<=n;i++){
				g[i].clear();
				vis[i]=0;
				f[i]=i;
			}
		}
	}
	return 0;
}
