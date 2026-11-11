#include<bits/stdc++.h>
using namespace std;
int dfn[1000010],n,k,a[1000010],Answer=INT_MAX,d[1000010];
vector<int> g[1000010],f[1000010];
void Tarjan(int x){
	dfn[x]=1;
	int cd=f[x].size();
	for(int i=0;i<cd;i++){
		if(!dfn[f[x][i]]){
			Tarjan(f[x][i]);
		}
	}
}
void DFS(int x,int st){
	if(x>k){
		int scc=0;
		for(int i=1;i<=k;i++){
			f[i].clear();
		}
		for(int i=1;i<=k;i++){
			int cd=g[i].size();
			for(int j=0;j<cd;j++){
				int x=lower_bound(a+1,a+1+k,g[i][j])-a;
				if(x!=n+1){
					f[a[i]].push_back(a[x]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(!dfn[i]){
				Tarjan(i);
				scc++;
			}
		}
		if(scc>2){
			return;
		}
		for(int i=1;i<=n;i++){
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int x=q.front(),cd=g[x].size(),y=lower_bound(a+1,a+1+n,x)-a;
				if(y!=n+1){
					break;
				}
				for(int i=0;i<cd;i++){
					if(!d[g[x][i]]){
						d[g[x][i]]=d[x]+1;
						q.push(g[x][i]);
					}
				}
			}
			int js=0;
			for(int i=1;i<=n;i++){
				js=max(js,d[i]);
			}
			Answer=min(js,Answer);
		}
		return;
	}
	for(int i=st;i<=n;i++){
		a[x]=i;
		DFS(x+1,i+1);
	}
}
void v(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	DFS(1,1);
	cout<<Answer<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		v();
	}
}
