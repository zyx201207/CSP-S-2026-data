#include<bits/stdc++.h>
//#define int long long
using namespace std;
using ll=long long;
using pi=pair<int,ll>;
const int maxn=5e5+10,maxm=5e2;
const ll infl=0x3f3f3f3f3f3f3f3f;
int c,n,m,D,q;
int a[maxn];
struct node{
	int u;
	ll w;
	bool operator <(const node &o)const{
		return w>o.w;
	}
};
vector<node>g[maxm];
vector<pi>vec[maxn];
ll b[maxm][maxm],d[maxm][maxm];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		for(int j=1;j<=l;j++){
			int u,w;
			cin>>u>>w;
			vec[u].push_back({i,w});
		}
	}
	memset(b,0x3f,sizeof(b));
	for(int i=1;i<=m;i++){
		for(int j=0;j<vec[i].size()-1;j++){
			for(int k=j+1;k<vec[i].size();k++){
				int u=vec[i][j].first,v=vec[i][k].first;
				ll w=vec[i][j].second+vec[i][k].second;
				b[u][v]=b[v][u]=min(b[u][v],w);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
//			cout<<b[i][j]<<' ';
			if(i!=j&&b[i][j]!=infl){
				g[i].push_back({j,b[i][j]});
			} 
		}
//		cout<<'\n';		
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++){
		priority_queue<node>q;
		q.push({i,0});
		d[i][i]=0;
		while(!q.empty()){
			auto x=q.top();
			q.pop();
			int u=x.u;
			ll cnt=x.w;
			for(auto y:g[u]){
				int v=y.u;
				ll w=y.w;
				if(d[i][u]+w<d[i][v]){
					d[i][v]=d[i][u]+w;
					q.push({v,d[i][u]+w});
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<d[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	while(q--){
		int u,v;
		cin>>u>>v;
		ll ans=infl;
		for(auto x:vec[u]){
			for(auto y:vec[v]){
				int i=x.first,j=y.first;
				ll res=x.second+y.second;
				ans=min(ans,a[u]+a[v]+res+d[i][j]);
			}
		}
		cout<<ans<<'\n';
	}
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
