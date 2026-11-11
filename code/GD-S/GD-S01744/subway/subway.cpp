#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=503,M=5e5+3;
int c,n,m,d,q,k,x,y,w[M];
ll dis[N][N],s;
vector<pair<int,int>>t[M];
inline void mn(ll&x,ll y){x=min(x,y);}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=i==j?0:1e18;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			t[x].push_back({y,i});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<t[i].size();j++){
			for(int k=0;k<t[i].size();k++){
				mn(dis[t[i][j].second][t[i][k].second],t[i][j].first+t[i][k].first);
			}
		}
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)mn(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		cin>>x>>y;
		s=1e18;
		for(int i=0;i<t[x].size();i++){
			for(int j=0;j<t[y].size();j++){
				mn(s,t[x][i].first+t[y][j].first+dis[t[x][i].second][t[y][j].second]);
			}
		}
		cout<<s+w[x]+w[y]<<'\n';
	}
}
