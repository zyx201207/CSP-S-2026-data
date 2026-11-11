#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >e[500005];
int n,m,c,p[505],d,q,w[500005],i,j,k,x,y,u,v,len;
long long dis[505][505];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(i=1; i<=n; i++) {
		cin>>p[i];
		for(j=1; j<=p[i]; j++) {
			cin>>x>>y;
			e[x].push_back(make_pair(i,y));
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(i=1; i<=n; i++)dis[i][i]=0;
	for(i=1; i<=m; i++) {
		len=e[i].size();
		for(j=0; j<len; j++) {
			for(k=0,u,v; k<len; k++) {
				if(j==k)continue;
				u=e[i][j].first;
				v=e[i][k].first;
				dis[u][v]=min(dis[u][v],1ll*(e[i][j].second+e[i][k].second));
				dis[v][u]=dis[u][v];
			}
		}
	}
	for(k=1; k<=n; k++) {
		for(i=1; i<=n; i++) {
			for(j=1; j<i; j++) {
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int lx,ly;
	long long ans;
	while(q--) {
		ans=1e18;
		cin>>x>>y;
		lx=e[x].size();
		ly=e[y].size();
		for(i=0; i<lx; i++) {
			for(j=0; j<ly; j++) {
				u=e[x][i].first;
				v=e[y][j].first;
				ans=min(ans,dis[u][v]+e[x][i].second+e[y][j].second);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
