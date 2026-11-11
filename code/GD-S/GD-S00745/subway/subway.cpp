#include<bits/stdc++.h>
using namespace std;
const int N=510,M=500010;
typedef long long ll;
const ll inf=1e18;
ll dis[N][N];
int c,n,m,d,q;
pair<int,int> v[M][25];
int tot[M];
int w[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		while(k--){
			int a,t;cin>>a>>t;
			v[a][++tot[a]]=make_pair(i,t);
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) dis[i][j]=inf;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=tot[i];j++)
			for(int k=1;k<=tot[i];k++)
				if(j!=k)
					dis[v[i][j].first][v[i][k].first]=min(dis[v[i][j].first][v[i][k].first],(ll)v[i][j].second+(ll)v[i][k].second);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y;cin>>x>>y;
		ll ans=inf;
		for(int j=1;j<=tot[x];j++)
			for(int k=1;k<=tot[y];k++)
				ans=min(ans,dis[v[x][j].first][v[y][k].first]+v[x][j].second+v[y][k].second);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

