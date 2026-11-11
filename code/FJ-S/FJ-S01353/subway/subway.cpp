#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
const ll inf=1e18;
int c,n,m,d,q;
ll w[N],k[505],e[505][505];
vector <pair<int,ll>> t[N]; 
vector <int> g[N]; 
void start(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			e[i][j]=e[j][i]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		e[i][i]=0;
	}
}
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j || j==k || i==k){
					continue;
				}
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		t[i].reserve(d);
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		g[i].reserve(k[i]);
		for(int j=1;j<=k[i];j++){
			int x;
			cin>>x;
			g[i].push_back(x);
			ll y;
			cin>>y;
			t[x].push_back({i,y});
		}
	}
	start();
	for(int i=1;i<=m;i++){
		for(auto j: t[i]){
			int x=j.first;
			ll v=j.second;
			for(auto k: t[i]){
				int y=k.first;
				if(x==y){
					continue;
				}
				ll w=k.second;
				e[x][y]=min(e[x][y],v+w);
				e[y][x]=min(e[y][x],v+w);
			}
		}
	}
	floyd();
	while(q--){
		int st,ed;
		cin>>st>>ed;
		ll ans=inf;
		for(auto i: t[st]){
			int x=i.first;
			ll v=i.second;
			for(auto j: t[ed]){
				int y=j.first;
				ll w=j.second;
				ans=min(ans,e[x][y]+v+w);
			}
		}
		ans+=w[st]+w[ed];
		cout<<ans<<'\n';
	}
	return 0;
}
