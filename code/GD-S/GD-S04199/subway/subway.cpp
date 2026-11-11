#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,int>
const int N=5e5+1000;
const ll inf=1e18;
ll dis[510][510],a[N];
int n,m,c,d,q;
vector<pii> vec[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	int k;ll t;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1,x;j<=k;j++){
			cin>>x>>t;
			vec[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)dis[i][j]=0;
			else dis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)vec[i].size();j++){
			for(int k=j+1;k<(int)vec[i].size();k++){
				int u=vec[i][j].first,v=vec[i][k].first;
				ll w=vec[i][j].second+vec[i][k].second;
				dis[u][v]=min(dis[u][v],w);
				dis[v][u]=min(dis[v][u],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=inf;
		for(int i=0;i<(int)vec[x].size();i++){
			for(int j=0;j<(int)vec[y].size();j++){
				int u=vec[x][i].first,v=vec[y][j].first;
				ll wu=vec[x][i].second,wv=vec[y][j].second;
				ans=min(ans,dis[u][v]+wu+wv);
			}
		}
		cout<<ans+a[x]+a[y]<<"\n";
	}
	return 0;
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
