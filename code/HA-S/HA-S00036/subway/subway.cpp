#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll linf=4000000000000000000;

int c,n,m,d,q,k[511];
int w[500011];
vector<array<int,2>> sta[500011];
ll dis[511][511];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
		cin >> w[i];
	for(short i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			int u,t;
			cin >> u >> t;
			sta[u].push_back({i,t});
		}
	}
	for(short i=1;i<=n;i++)
		for(short j=1;j<=n;j++)
			dis[i][j]=linf;
	for(short i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(short j=0;j<sta[i].size();j++)
			for(short k=0;k<sta[i].size();k++)
				if(j!=k)
					dis[sta[i][j][0]][sta[i][k][0]]=sta[i][j][1]+sta[i][k][1];
	}
	for(short k=1;k<=n;k++)
		for(short i=1;i<=n;i++)
			for(short j=1;j<=n;j++){
				if(dis[i][k]==linf||dis[k][j]==linf)
					continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
	while(q--){
		int u,v;
		ll ans=linf;
		cin >> u >> v;
		for(short i=0;i<sta[u].size();i++)
			for(short j=0;j<sta[v].size();j++)
				ans=min(ans,dis[sta[u][i][0]][sta[v][j][0]]+w[u]+w[v]+sta[u][i][1]+sta[v][j][1]);
		cout << ans << '\n';
	}
	return 0;
}


