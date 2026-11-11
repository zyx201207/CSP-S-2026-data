#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+50;
const int inf=LLONG_MAX;
int c,n,m,D,q;
int zd[N]={0};
struct edge{int v,w;};
vector<edge>d[N];
bool vis[N];
int dfs(int p,int lst){
	int cnt=0,qwq=INT_MAX;
	vis[p]=1;
	if(p==lst)return cnt;
	for(auto v:d[p]){
		if(!vis[v.v])qwq=min(qwq,dfs(v.v,lst)+v.w);
	}
	return cnt+qwq;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++){
		int x;cin>>x;
		d[0].push_back({i,x});
		d[i].push_back({0,x});
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=2*k;j++){
			if(j%2==0){
				int t;cin>>t;
				if(j>2){
					int u=zd[j/2],v=zd[j/2-1];
					d[u].push_back({v,t});
					d[v].push_back({u,t});
				}
			}else cin>>zd[j/2+1];
		}
	}
	while(q--){
		int u,v;cin>>u>>v;
		cout<<dfs(u,v)<<endl;
	}return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
