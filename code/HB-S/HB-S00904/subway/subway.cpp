#include <bits/stdc++.h>
using namespace std;

const int N = 505, M = 5e5 + 5,D = 21;
typedef long long ll;
int c,n,m,d,q;

vector<pair<int,int> >lines[M];
ll w[M];
ll dis[N][N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int T;
		cin>>T;
		while(T--){
			int x,y;
			cin>>x>>y;
			lines[x].push_back({i,y});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<lines[i].size();j++){
			for(int k=j+1;k<lines[i].size();k++){
				int u=lines[i][j].first,v=lines[i][k].first;
				ll ew=lines[i][j].second+lines[i][k].second;
				if(dis[u][v]>ew)
					dis[u][v]=dis[v][u]=ew;
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j];
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<0<<'\n';
			continue;
		}
		ll ans=LLONG_MAX;
		for(int i=0;i<lines[x].size();i++){
			for(int j=0;j<lines[y].size();j++){
				int u=lines[x][i].first,v=lines[y][j].first;
				ll d1=lines[x][i].second,d2=lines[y][j].second;
				if(ans>w[x]+w[y]+d1+d2+dis[u][v])
					ans=w[x]+w[y]+d1+d2+dis[u][v];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}