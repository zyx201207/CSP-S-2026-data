#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int M = 1e5+5;
int c,n,m,d,q;
int w[N],t[N][M],l[N][M],le[N];
bool vis[N][M];
vector<int>g[N][M];
void dij(int st,int end){
	long long ans = 1e18;
	vector<bool> vid(M,0);
	priority_queue< pair<long long,pair<int,int>> , vector<pair<long long,pair<int,int>>> , greater<pair<long long,pair<int,int>>>> q;
	for(int i=1;i<=n;i++)if(vis[i][st])q.push({w[st]+t[i][st],{st,i}});
	while(q.size()){
		auto f = q.top();
		long long now = f.first;
		int  u = f.second.first , line = f.second.second;
//		cout << now<<" "<<u<<" "<< line << "\n" << ans << "\n";
		q.pop();
		if(u==end)ans = min(ans,now+w[u]+t[line][u]);
		if(vid[u])continue;
		vid[u]=1;
		for(int i=1;i<=n;i++){
			if(vis[i][u]){
				int plus = 0;
				if(i!=line)plus = t[line][u]+t[i][u];
				for(auto v : g[i][u])q.push({now+plus,{v,i}});
			}
		}
	}printf("%lld\n",ans);
	return;
}int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&le[i]);
		for(int j=1;j<=le[i];j++){
			scanf("%d",&l[i][j]);
			scanf("%d",&t[i][l[i][j]]);
			vis[i][l[i][j]]=1;
		}for(int j=2;j<=le[i];j++){
			int u = l[i][j-1],v = l[i][j];
			g[i][u].push_back(v);
			g[i][v].push_back(u);
		}
	}/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout << t[i][j] << " ";
		}cout << "\n";
	}*/
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v);
		dij(u,v);
	}
	return 0;
}
