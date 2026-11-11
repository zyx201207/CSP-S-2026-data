#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+15;
#define ll long long
int n,k;
vector<int> G[maxn];
int res;
void dfs(int u,int fa,int st,int dep){
	if(st>>u-1&1)return res=max(res,dep),void();
	for(int v:G[u])if(v!=fa)dfs(v,u,st,dep+1);
}
int f[maxn];
int find(int x){if(!f[x])return x;return f[x]=find(f[x]);
}
void link(int x,int y){
	if((x=find(x))==(y=find(y)))return;f[x]=y;
}
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)G[i].clear();
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int ans=n;
	for(int s=0;s<(1<<n);++s){
		if(__builtin_popcount(s)!=k)continue;
		for(int i=1;i<=n;++i)f[i]=0;
		for(int j=1;j<=n;++j)if(s>>j-1&1){
			for(int u:G[j])if(s>>u-1&1)link(j,u);
		}
		map<int,int> vis;
		int cnt=0;
		for(int j=1;j<=n;++j)if(s>>j-1&1){
			int k=find(j);
			if(!vis[k])++cnt,vis[k]=1;
			if(cnt>2)break;
		}
		if(cnt>2)continue;
		res=0;
		for(int i=1;i<=n;++i)dfs(i,0,s,0);
		ans=min(ans,res);
	}
	printf("%d\n",ans);
}
int Number;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	for(int tc=(scanf("%d%d",&Number,&tc),tc);tc--;)solve();
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/

