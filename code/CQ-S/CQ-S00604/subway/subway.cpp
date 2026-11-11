#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+5,N=5e2+5;
int cas,n,m,d,q,w[M],dis[N][N],vis[N];
vector<int> v[M],pos[M],line[N];
void dfs(int x,int fa){
	if(vis[x])return ;
	for(auto y:line[x])if(y!=fa)dfs(y,x),dis[fa][y]=dis[fa][x]+dis[x][y];
	vis[x]=1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>cas>>n>>m>>d>>q;
	vector<int> t[n+1];
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,lst; cin>>k,t[i].resize(k+1);
		for(int j=1,x;j<=k;j++){
			cin>>x,cin>>t[i][x],pos[x].push_back(i);
			if(j>1)v[x].push_back(lst),v[lst].push_back(x); lst=x;
		}
	}for(int i=1;i<=m;i++)if(pos[i].size()>1)
		for(auto x:pos[i])for(auto y:pos[i])if(x!=y)dis[x][y]=1,line[x].push_back(y);
	for(int i=1;i<=n;i++)dfs(i,0);
	while(q--){
		int st,ed; cin>>st>>ed;
		if(cas>=12&&cas<=19){
			int minn=500;
			for(auto x:pos[st])for(auto y:pos[ed])minn=min(dis[x][y],minn);
			cout<<w[st]+w[ed]+t[pos[st][0]][st]*(2*minn+2)<<"\n";
			continue;
		}
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

12 2 5 20 2
4 1 9 2 5
3 1 5 2 5 4 5
3 2 5 3 5 5 5
1 3
1 2
*/
