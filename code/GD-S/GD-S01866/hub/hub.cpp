#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1000000000000000000ll
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int dep[1000010],u[1000010],v[1000010],fa[1000010],dis[1000010],f[1000010][30];
vector <int> mp[1000010];
bool bui[1000010];
void dfs(int now,int fa) {
	f[now][0]=fa;
	dep[now]=dep[fa]+1;
	for(int i:mp[now]) {
		if(i!=fa) {
			dfs(i,now);
		}
	}
	return;
}
int find(int x) {
	if(fa[x]==x) {
		return x;
	} else {
		return fa[x]=find(fa[x]);
	}
}
int d(int a,int b) {
	int x=a,y=b;
	if(a==b) {
		return 0;
	} 
	if(dep[a]<dep[b]) {
		swap(a,b);
	}
	int cha=dep[a]-dep[b];
	for(int i=0; i<=21; i++) {
		if((cha>>i)&1) {
			a=f[a][i];
		}
	}
	if(a==b) {
		return cha;
	}
	for(int i=21; i>=0; i--) {
		if(f[a][i]!=f[b][i]) {
			a=f[a][i];
			b=f[b][i];
		}
	}
	int lca=f[a][0];
	return dep[x]-dep[lca]+dep[y]-dep[lca];
}
signed main() {
	FAST
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) {
		int n,k;
		cin>>n>>k;
		for(int i=1; i<=n; i++) {
			mp[i].clear(); 
		}
		for(int i=1; i<n; i++) {
			cin>>u[i]>>v[i];
			mp[u[i]].push_back(v[i]);
			mp[v[i]].push_back(u[i]);
		}
		if(k<=2) {
			dfs(1,0);
			int pos1,maxx=-1; 
			for(int i=1; i<=n; i++) {
				if(dep[i]>maxx) {
					maxx=dep[i];
					pos1=i;
				}
			}
			dfs(pos1,0);
			int pos2;
			maxx=-1;
			for(int i=1; i<=n; i++) {
				if(dep[i]>maxx) {
					maxx=dep[i];
					pos2=i;
				}
			}
			for(int i=1; i<=21; i++) {
				for(int j=1; j<=n; j++) {
					f[j][i]=f[f[j][i-1]][i-1];
				}
			}
			int pos3=pos2;
			for(int i=1; i<=dep[pos2]/2; i++) {
				pos3=f[pos3][0];
			}
			int ans=inf;
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					if(i!=j) {
						int now=max(max(min(d(i,pos1),d(i,pos2)),d(i,pos3)),max(min(d(j,pos1),d(j,pos2)),d(j,pos3)));
						ans=min(ans,now);
					}
				}
			}
			cout<<ans<<"\n";
		} else {
			int ans=inf;
			for(int i=0; i<(1<<n); i++) {
				int cnt=0;
				queue <int> q;
				for(int j=1; j<=n; j++) {
					fa[j]=j;
					dis[j]=-1;
					if((i>>(j-1))&1) {
						cnt++;
						q.push(j);
						dis[j]=0;
						bui[j]=true;
					} else {
						bui[j]=false;
					}
				}
				if(cnt==k) {
					for(int j=1; j<n; j++) {
						if(bui[u[j]]&&bui[v[j]]) {
							int x=find(u[j]),y=find(v[j]);
							if(x!=y) {
								fa[x]=y;
							}
						}
					}
					int c=0;
					for(int j=1; j<=n; j++) {
						if(bui[j]==true&&find(j)==j) {
							c++;
						}
					}
					if(c<=2) {
						int maxx=0;
						while(!q.empty()) {
							int now=q.front();
							q.pop();
							for(int j:mp[now]) {
								if(dis[j]==-1) {
									dis[j]=dis[now]+1;
									q.push(j);
									maxx=max({maxx,dis[j]});
								}
							}
						}
						ans=min({ans,maxx});
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
