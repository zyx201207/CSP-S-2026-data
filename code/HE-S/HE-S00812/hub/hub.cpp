#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans,fa[100010],dep[100010],f[100010];
vector<int> mp[100010];
vector<int> walk;
void dfs(int x,int d,int faa){
	dep[x]=d;
	f[x]=faa;
	for (int i=0;i<mp[x].size();i++){
		if (dep[mp[x][i]]==0){
			dfs(mp[x][i],d+1,x);
		}
	}
	return;
}
int find(int x){
	if (fa[x]==x){
		return x;
	}else{
		return fa[x]=find(fa[x]);
	}
}
int lca(int x,int y){
	if (dep[x]<dep[y]){
		swap(x,y);
	}
	while (dep[x]!=dep[y]){
		x=f[x];
	}
	while (x!=y&&x!=-1&&y!=-1){
		x=f[x];
		y=f[y];
	}
	return x;
}
void dfsa(int x,int step){
	if (step==k){
		int ansl=-2e9;
		for (int i=0;i<walk.size();i++){
			for (int j=i+1;j<walk.size();j++){
				long long x=walk[i],y=walk[j];
				long long tq=lca(x,y);
				int anss=dep[x]+dep[y]-2*dep[tq];
				ansl=max(ansl,anss);
				if (ansl>ans){
					return;
				}
			} 
		}
		ans=min(ans,ansl);
		return;
	}
	if (x>n||step+(n-x+1)<k){
		return;
	}
	walk.push_back(x);
	dfsa(x+1,step+1);
	walk.pop_back();
	dfsa(x+1,step);
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	for (int tim=1;tim<=t;tim++){
		for (int i=1;i<=n;i++){
			fa[i]=i;
			mp[i].clear();
			dep[i]=0;
		}
		ans=1e9;
		cin >> n >> k;
		for (int i=1;i<n;i++){
			int u,v;
			cin >> u >> v;
			mp[u].push_back(v);
			mp[v].push_back(v);
		}
		dfs(1,1,-1);
		walk.clear();
		dfsa(1,0);
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
