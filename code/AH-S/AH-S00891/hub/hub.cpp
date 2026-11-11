#include<bits/stdc++.h>
using namespace std;
int c,t,n,f[100055],dis[100005],k,mx[100006],ans;
vector<int>e[100005];
void dfs(int u,int fa){
	dis[u]=dis[fa]+1;
	for(int i=0,v;i<e[u].size();i++){
		v=e[u][i];
		if(v!=fa)dfs(v,u);
	}
}
void work(){
	int cc=0;
	for(int i=1;i<=n;i++){
		if(f[i]){
			for(int j=0,v;j<e[i].size();j++){
				v=e[i][j];
				if(f[v])cc++;
			}
		}
	}
	int p=k-cc/2,mk=0,res=0;
	if(p>2)return ;
	for(int i=1;i<=n;i++){
		dis[0]=-1;
		dfs(i,0);
		mk=1e9;
		for(int j=1;j<=n;j++){
			if(f[j])
			mk=min(mk,dis[j]);
		}
		res=max(res,mk);
	}
	ans=min(ans,res);
}
void dfs1(int u,int c){
	if(c==k){
		work();
		return ;
	}
	if(c+(n-u+1)<k)return ;
	f[u]=1;
	dfs1(u+1,c+1);
	f[u]=0;
	dfs1(u+1,c);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=1e9;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);e[v].push_back(u);
		}
		dfs1(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
