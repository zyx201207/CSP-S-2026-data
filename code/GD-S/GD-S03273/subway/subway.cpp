#include <bits/stdc++.h>
#define MAXN 500005
using ll = long long;
using namespace std;
int c,n,m,d,q;
ll w[MAXN];
struct node{
	int v,w;
};
vector<node> vec[MAXN];
ll dis[505][505];
inline void chkmin(ll &x,ll y){
	if(x>y)x=y;
} 
int main(){
#ifndef SVK
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){
			int x,t; cin>>x>>t;
			vec[x].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)dis[i][i] = 0;
	
	for(int i=1;i<=m;i++){
		int r = (int)vec[i].size();
		for(int x=0;x<r;x++){
			for(int y=x+1;y<r;y++){
				chkmin(dis[vec[i][x].v][vec[i][y].v], 
					vec[i][x].w+vec[i][y].w);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j] = min(dis[i][j], dis[j][i]);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				chkmin(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y; cin>>x>>y;
		ll ans = LLONG_MAX;
		for(node i : vec[x]){
			for(node j : vec[y]){
				ans = min(ans,
					w[x]+w[y]+dis[i.v][j.v]+i.w+j.w);
			}
		}
		cout<<ans<<"\n";
	}

	return 0;
}


