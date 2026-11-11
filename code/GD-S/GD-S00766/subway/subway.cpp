#include<bits/stdc++.h>
using namespace std;
#define ve vector
#define pb push_back
#define pii pair<int,ll>
#define mp make_pair
#define fi first
#define se second
#define ll long long
const int N=5e5+5,M=505;
ll w[N],dis[M][M];
ve<pii>e[N],q[N];
struct node{
	int x;ll d;
	friend bool operator<(node x,node y){
		return x.d>y.d;
	}
};
priority_queue<node>dl;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,Q;
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int x,y;k;k--){
			cin>>x>>y;
			for(pii j:q[x])
				e[i].pb(mp(j.fi,j.se+y)),
				e[j.fi].pb(mp(i,j.se+y));
			q[x].pb(mp(i,y));
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=(i==j?0:1e15);
	for(int i=1;i<=n;i++){
		dl.push({i,0});
		while(!dl.empty()){
			node u=dl.top();dl.pop();
//			cerr<<u.fi<<'\n';
			if(u.d>dis[i][u.x])continue;
			for(pii E:e[u.x]){
				if(dis[i][E.fi]>u.d+E.se)
					dis[i][E.fi]=u.d+E.se,
					dl.push({E.fi,u.d+E.se});
			}
		}
//		cerr<<"*****\n";
	}
	for(int x,y;Q;Q--){
		cin>>x>>y;ll ans=1e15;
		for(pii X:q[x])
			for(pii Y:q[y])
				ans=min(ans,dis[X.fi][Y.fi]+X.se+Y.se+w[x]+w[y]);
		cout<<ans<<'\n';
	}
	return 0;
}
/*


*/
