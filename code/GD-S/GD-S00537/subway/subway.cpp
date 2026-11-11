#include<bits/stdc++.h>
using namespace std;
vector<pair<int,long long> > d[500001];
long long c,t,n,m,x,y,q,k,ans,w[500001],dis[501][501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dis,1,sizeof(dis));
	cin>>c>>n>>m>>c>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>c>>t;
			d[c].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<d[i].size();j++){
			for(int k=0;k<d[i].size();k++){
				dis[d[i][j].first][d[i][k].first]=min(dis[d[i][j].first][d[i][k].first],d[i][j].second+d[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		ans=9223372036854775807;
		cin>>x>>y;
		for(int j=0;j<d[x].size();j++){
			for(int k=0;k<d[y].size();k++){
				ans=min(ans,dis[d[x][j].first][d[y][k].first]+d[x][j].second+d[y][k].second);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
