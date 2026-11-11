#include<bits/stdc++.h>
#define st first
#define nd second
#define inf int(1e9+1)
#define INF int(1E18+1)
using namespace std;
typedef long long L;
typedef unsigned long long UL;
int w[500001];
bool vis[500001];
vector<pair<int,int>>g[501];
L dfs(int now,int end,L step){
	L res,ans=inf;
	if(now==end){
		return step;
	}
	for(auto i:g[now]){
		if(vis[i.st]){
			continue;
		}
		vis[i.st]=1;
		res=dfs(i.st,end,step+i.nd);
		if(res){
			ans=min(ans,res);
		}
		vis[i.st]=0;
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,q,l,u,v,s,T;
	cin>>c>>n>>m>>q>>T;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>l>>v;
		for(int j=1;j<l;j++){
			u=v;
			cin>>v>>s;
			g[u].push_back({v,s});
			g[v].push_back({u,s});
		}
	}
	while(T--){
		memset(vis,0,sizeof vis);
		cin>>u>>v;
		cout<<dfs(u,v,w[u]+w[v])<<endl;
	}
	return 0;
}
