#include <bits/stdc++.h> 
using namespace std;
int c,T,n,m;
vector<int> fir[1000005];
int vis[1000005],S,ans,zc;
void dfs(int u,int fa,int z){
	vis[u]=1;
	for(auto v:fir[u]){
		if(v!=fa&&((z>>(v-1))&1)){
			dfs(v,u,z);
		}
	}
}
void sol(int u,int fa,int jl){
	if(vis[u])jl=0;
	zc=max(zc,jl);
	for(auto v:fir[u]){
		if(v!=fa){
			sol(v,u,jl+1);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			fir[i].clear();vis[i]=0;
		}
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			fir[u].emplace_back(v);
			fir[v].emplace_back(u);
		}
		if(c==13||c==14){
			if(n==m)cout<<0<<'\n';
			else{
				n/=2;
				if(m>=n)cout<<1<<'\n';
				else{
					if(m==1)cout<<n/2+1<<'\n';
					else cout<<(n-m+3)/4+1<<'\n';
				}
			}
			continue;
		}
		S=(1<<n)-1,ans=n;
		for(int i=0,w;i<=S;i++){
			w=0;
			for(int j=1;j<=n;j++)
				if((i>>(j-1))&1)w++;
			if(w!=m)continue;
			w=0;
			for(int j=1;j<=n;j++)vis[j]=0;
			for(int j=1;j<=n;j++){
				if(!vis[j]&&((i>>(j-1))&1)){
					w++;
					dfs(j,0,i);
				}
			}
			if(w>2)continue;
			zc=0;
			for(int j=1;j<=n;j++){
				if(vis[j]){
					sol(j,0,0);
					break;
				}
			}
			ans=min(ans,zc);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
