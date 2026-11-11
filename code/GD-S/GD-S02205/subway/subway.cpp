#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=5e5+5;
int dis[505][505],c,n,m,d,q,w[N];
vector<pii>v[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,a,b;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>b;
			v[a].push_back({i,b});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		if(v[i].size()<=1)continue;
		for(int j=0;j<v[i].size();j++){
			for(int k=0;k<j;k++){
				int a=v[i][j].first,b=v[i][k].first,sum=v[i][j].second+v[i][k].second;
				dis[a][b]=dis[b][a]=min(dis[a][b],sum);
			} 
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&i!=k&&k!=j){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]); 
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	while(q--){
		int x,y,ans=1e18;
		cin>>x>>y;
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				int a=v[x][i].first,b=v[x][i].second,c=v[y][j].first,d=v[y][j].second;
				ans=min(ans,w[x]+w[y]+dis[a][c]+b+d);
			
			}
		}cout<<ans<<'\n';
	}
   return 0;
}


