#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1010
#define il inline
/*
ÕÌ…œ≥‘ ≤√¥ 
*/
int n,k;
vector<int> G[N];
int get_1(int s){
	int res=0;
	while(s){
		if(s&1) ++res;
		s>>=1;
	}
	return res;
}
int dis[N][N];
void dfs(int u,int fa,int rt){
	dis[rt][u]=(fa==-1)?0:dis[rt][fa]+1;
	for(int v:G[u]){
		if(v!=fa) dfs(v,u,rt);
	}
}
int D[N];
int rt[N];
int find(int u){
	while(u!=rt[u]) u=rt[u]=rt[rt[u]];
	return u;
}
int merge(int u,int v){
	if((u=find(u))==(v=find(v))) return 0;
	rt[u]=v;
	return 1;
}
void solve(){
	cin>>n>>k;
	for(int i=0;i<n;i++) G[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		--u,--v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	if(n==k) {
		cout<<0<<'\n';
		return ;
	}
	for(int i=0;i<n;i++) dfs(i,-1,i);
	int ans=0x3f3f3f3f,res=0;
	for(int mask=0;mask<(1<<n);mask++){
		if(get_1(mask)!=k) continue;
		int kt=k;
		for(int i=0;i<n;i++) rt[i]=i;
		for(int u=0;u<n;u++) {
			for(int v:G[u]){
				if((mask>>u&1)&&(mask>>v&1)) {
					kt-=merge(u,v);
				}
			}
		}
		if(kt>2) continue;
		res=0;
		for(int i=0;i<n;i++){
			D[i]=0x3f3f3f3f;
			for(int j=0;j<n;j++){
				if(mask>>j&1){
					D[i]=min(D[i],dis[i][j]);
				}
			}
			res=max(res,D[i]);
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
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
*/

