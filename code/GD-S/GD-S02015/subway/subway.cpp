#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
int c,n,m,d,q;
int w[MAXN];
vector<pair<int,int> >e[MAXN];
long long dis[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			dis[i][j]=(i==j?0:0x3f3f3f3f3f3f3f3fll); 
		}
	}
	for(int i=1;i<=n;++i){
		int k,x,t;cin>>k;
		while(k--){
			cin>>x>>t;
			e[x].emplace_back(i,t);
		}
	}
	for(int i=1;i<=m;++i){
		for(auto it:e[i])for(auto it2:e[i]){
			dis[it.first][it2.first]=min(dis[it.first][it2.first],it.second+it2.second+0ll);
		}
	}
	for(int j=1;j<=n;++j){
		for(int i=1;i<=n;++i){
			for(int k=1;k<=n;++k){
				dis[i][k]=min(dis[i][k],dis[i][j]+dis[j][k]);
			}
		} 
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long res=LLONG_MAX;
		for(auto it:e[x]){
			for(auto it2:e[y]){
				res=min(res,it.second+it2.second+dis[it.first][it2.first]);
			}
		}
		cout<<res+w[x]+w[y]<<'\n';
	}
}
