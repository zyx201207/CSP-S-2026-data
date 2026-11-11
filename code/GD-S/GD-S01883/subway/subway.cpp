#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],dis[505][505];
vector<pair<long long,long long> > line[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)cin>>w[i];
	for(long long i=1,x;i<=n;i++){
		cin>>x;
		for(long long j=1,a,t;j<=x;j++)cin>>a>>t,line[a].push_back(make_pair(i,t));
	}
	for(long long i=1;i<=n;i++)for(long long j=1;j<=n;j++)dis[i][j]=2e18;
	for(long long i=1;i<=n;i++)dis[i][i]=0;
	for(long long i=1;i<=m;i++){
		for(long long j=0;j<line[i].size();j++){
			for(long long k=j+1;k<line[i].size();k++){
				long long u=line[i][j].first,v=line[i][k].first,w=line[i][j].second+line[i][k].second;
				dis[u][v]=min(dis[u][v],w);
				dis[v][u]=min(dis[v][u],w);
			}
		}
	}
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		long long x,y,ans=2e18;
		cin>>x>>y;
		for(long long i=0;i<line[x].size();i++){
			for(long long j=0;j<line[y].size();j++){
				ans=min(ans,w[x]+w[y]+dis[line[x][i].first][line[y][j].first]+line[x][i].second+line[y][j].second);
			}
		}
		cout<<ans<<'\n';
	}
}
/*
hyw
14:35 AC T1
15:02 AC T2
how speed!!! 
I never play this speed in any competition before
possible this T2 too easy
pls describe me in luogu,my uid is 935574 pls.
*/
