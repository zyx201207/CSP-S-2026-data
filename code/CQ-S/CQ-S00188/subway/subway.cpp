#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18; 
const int N=5e5+10;
const int M=510;

int c, n, m, sd, q;
int tw[N];
vector<int>v[N];
vector<int>d[N];
int dis[M][M];
int w[M][M];



signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	

	scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &sd, &q);
	for(int i=1; i<=m; i++) scanf("%lld", &tw[i]);
	for(int i=1; i<=n; i++)
	{
		int k;
		cin>>k;
		for(int j=1; j<=k; j++)
		{
			int a, t;
			scanf("%lld %lld", &a, &t);
			v[a].push_back(i);
			d[a].push_back(t);
		}
	}
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(i==j) w[i][j]=0;
			else w[i][j]=inf;
		
	for(int i=1; i<=m; i++)
	{
		for(int j=0; j<v[i].size(); j++)
			for(int k=j+1; k<v[i].size(); k++)
			{
				int su=v[i][j];
				int sv=v[i][k];
				w[su][sv]=min(w[su][sv], d[i][j]+d[i][k]);
				w[sv][su]=min(w[sv][su], d[i][j]+d[i][k]);
			}
	}
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) dis[i][j]=w[i][j];
	
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
	
	while(q--)
	{
		int s, t, ans;
		scanf("%lld %lld", &s, &t);
		ans=inf;
		for(int i=0; i<v[s].size(); i++)
			for(int j=0; j<v[t].size(); j++)
			{
				int tu=v[s][i];
				int tv=v[t][j];
				ans=min(ans, d[s][i]+dis[ v[s][i] ][ v[t][j] ]+d[t][j]);
			}
		ans=ans+tw[s]+tw[t];
		printf("%lld\n", ans);
	}	
	
	
	
	return 0;
}
