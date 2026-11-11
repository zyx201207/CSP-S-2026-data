#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e2+5,M=5e5+5;
const ll inf=LLONG_MAX; 
int c,n,m,d,q,k,w[M],a,t,i,j,x,y; ll dis[M];
vector<pair<int,ll>> e[N];
void add(int u,int v,ll w) {e[u].push_back({v,w}),e[v].push_back({u,w});}
int main() {
	ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;++i) cin>>w[i];
	for(i=1;i<=n;++i) {
		cin>>k;
		for(j=1;j<=k;++j) cin>>a>>t,add(a,i+m,t);
	}
	while(q--) {
		cin>>x>>y;
		for(i=1;i<=m+n;++i) dis[i]=(i==x?0:inf);
		priority_queue<pair<ll,int>> q;
		q.push({0,x});
		while(!q.empty()) {
			pair<ll,int> noww=q.top(); q.pop();
			ll z=noww.first; int u=noww.second;
			for(pair<int,ll> to:e[u]) {
				ll w=to.second; int v=to.first;
				if(dis[v]==inf||dis[v]!=inf&&dis[v]>=z+w) 
					dis[v]=min(dis[v],z+w),q.push({dis[v],v});
			}
		}
		cout<<dis[y]+w[x]+w[y]<<'\n';
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
