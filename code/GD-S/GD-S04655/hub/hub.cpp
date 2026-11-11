#include <bits/stdc++.h>
#define maxn 1000005
#define int long long
using namespace std;
int C,t,n,k,l,dep[maxn];
vector<int>g[maxn];
void dfs(int p,int fa){
	for(auto q:g[p]){
		if(q==fa) continue;
		dep[q]=dep[p]+1;
		if(dep[q]>dep[l]) l=q;
		dfs(q,p);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int u,v;
	cin>>C>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear(),dep[i]=0;;
		for(int i=1;i<=n-1;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		l=1;
		dfs(1,0);
		for(int i=1;i<=n;i++) dep[i]=0;
		dfs(l,0);
		cout<<(dep[l]+1)/3<<"\n";
	}
	cout.flush();
}

