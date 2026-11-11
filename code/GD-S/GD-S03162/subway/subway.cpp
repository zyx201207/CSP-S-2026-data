#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int M=5e5+10;
int c,n,m,d,q,w[M];
long long dis[505][505];
vector<pii> v[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin >> k;
		while(k--)
		{
			int x,y;
			cin >> x >> y;
			v[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) dis[i][j]=dis[j][i]=2e9+10;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			int t1=v[i][j].first,t2=v[i][j].second;
			for(int k=j+1;k<v[i].size();k++)
			{
				int t3=v[i][k].first,t4=v[i][k].second;
				dis[t1][t3]=dis[t3][t1]=min(dis[t1][t3],(long long)t2+t4);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(k==i) continue;
			for(int j=i+1;j<=n;j++)
			{
				if(k==j) continue;
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		long long ans=0;
		cin >> x >> y;
		for(int i=0;i<v[x].size();i++)
		{
			for(int j=0;j<v[y].size();j++)
			{
				int t1=v[x][i].first,t2=v[y][j].first;
				int t3=v[x][i].second,t4=v[y][j].second;
				if(!ans) ans=w[x]+t3+dis[t1][t2]+t4+w[y];
				else ans=min(ans,w[x]+t3+dis[t1][t2]+t4+w[y]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
