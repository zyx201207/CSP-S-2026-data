#include<bits/stdc++.h>
#define inf 2e9+1
using namespace std;
int c,n,m,d,q;
int w[1000001],k[1000001];
int a[501][200011],t[501][200011];
int b[511][511];
int dist[511];
struct node
{
	int x,d;
	bool operator < (const node&a) const 
	{
		return d<a.d;
	}
};
void solve()
{
	int x,y;
	cin >> x >> y;
	for(int i=0;i<=m;i++) dist[i]=inf;
	dist[x]=0;
	priority_queue<node> que;
	que.push({x,0});
	while(!que.empty())
	{
		int id=que.top().x,dis=que.top().d;
		que.pop();
		for(int j=1;j<=m;j++)
		{
			if(j == id) continue; 
			if(dist[j] > dis+b[id][j])
			{
				dist[j]=dis+b[id][j];
				que.push({j,dist[j]});
			}	
		}	
	}
	long long ans=w[x]+dist[y]+w[y];
	cout << ans << endl;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=0;i<=m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			b[i][j]=b[j][i]=inf;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin >> k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
		for(int x=1;x<=k[i];x++)
		{
			for(int y=x+1;y<=k[i];y++)
			{
				b[a[i][x]][a[i][y]]=min(b[a[i][x]][a[i][y]],t[i][x]+t[i][y]);
				b[a[i][y]][a[i][x]]=min(b[a[i][y]][a[i][x]],t[i][x]+t[i][y]);
			}
		}
	}
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			if(b[i][j] == inf) cout << "inf ";
//			else cout << b[i][j] << " ";
//		}
//		cout << endl;
//	}
	while(q--) solve();
	return 0;
}