#include<bits/stdc++.h>
using namespace std;
int c,t,vis[15],f[15],dep[15],k[15],n,K;
vector<int> g[15];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	f[x]=y;
}
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	k[x]=fa;
	for(auto v:g[x]){
		if(v!=fa){
			dfs(v,x);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		cin>>n>>K;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		memset(k,0,sizeof(k));
		dfs(1,0);
		int ans=10005;
		for(int s=0;s<(1<<n);s++){
			memset(vis,0,sizeof(vis));
			int cnt=0;
			for(int j=0;j<n;j++){
				f[j+1]=j+1;
				if((s>>j)&1){
					cnt++;
					vis[j+1]=1;
				}
			}
			if(cnt==K){
				for(int i=1;i<=n;i++){
					if(vis[i]==1){
						for(auto v:g[i]){
							if(vis[v]==1){
								merge(i,v);
							}
						}
					}
				}
				int lst1=f[1],lst2=0,fl=1;
				for(int i=1;i<=n;i++){
					if(f[i]!=lst1){
						if(lst2==0){
							lst2=f[i];
						}else{
							fl=0;
						}
					}
				}
				if(fl==1){
					int an=10005;
					for(int i=1;i<=n;i++){
						for(int j=1;j<=n;j++){
							if(vis[i]==1&&vis[j]==1){
								int u=i,v=j;
								if(dep[u]<dep[v]) swap(u,v);
								int tmp=0;
								while(dep[u]<dep[v]){
									tmp++;
									u=k[u];
								}
								while(u!=v){
									u=k[u],v=k[v];
									tmp+=2;
								}
								an=min(an,tmp);
							}
						}
					}
					ans=min(ans,an);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
