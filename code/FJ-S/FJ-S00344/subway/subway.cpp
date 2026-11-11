#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,m,a[500005],dis[505][505];
vector<pair<int,int> > v[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>q>>m>>n>>q>>q;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=999911659998244353ll;
		}
	}
	for(int i=1;i<=m;i++){
		dis[i][i]=0;
		int k,x,y;
		scanf("%lld",&k);
		while(k--){
			scanf("%lld%lld",&x,&y);
			v[x].push_back(make_pair(y,i));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=0;k<v[i].size();k++){
				pair<int,int> x=v[i][j],y=v[i][k];
				dis[x.second][y.second]=min(dis[x.second][y.second],x.first+y.first);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		int ans=999911659998244353ll;
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				ans=min(ans,v[x][i].first+v[y][j].first+dis[v[x][i].second][v[y][j].second]);
			}
		}
		printf("%lld\n",ans+a[x]+a[y]);
	}
	return 0;
}
