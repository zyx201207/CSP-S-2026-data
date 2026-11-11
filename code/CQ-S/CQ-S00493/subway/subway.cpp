#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1000000000000000000;

int Testnum,n,m,D,q;

const int M=5e5+5;
const int N=505;
int a[M];

struct node
{
	signed x,d;
}sub[M][25];
int cnt[M];

int dis[N][N];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>Testnum>>m>>n>>D>>q;
	for (int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	for (int i=1; i<=m; i++)
	{
		int k;
		cin>>k;
		while (k--)
		{
			int x,d;
			cin>>x>>d;
			++cnt[x];
			sub[x][cnt[x]]={i,d};
		}
	}
	for (int i=1; i<=m; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (i==j) continue;
			dis[i][j]=INF;
		}
	}
	for (signed x=1; x<=n; x++)
	{
		for (signed i=1; i<=cnt[x]; i++)
		{
			for (signed j=i+1; j<=cnt[x]; j++)
			{
				dis[sub[x][i].x][sub[x][j].x]=dis[sub[x][j].x][sub[x][i].x]=min(dis[sub[x][i].x][sub[x][j].x],1ll*sub[x][i].d+sub[x][j].d);
			}
		}
	}
	
	for (int k=1; k<=m; k++)
	{
		for (int i=1; i<=m; i++)
		{
			for (int j=1; j<=m; j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	
	while (q--)
	{
		int l,r;
		cin>>l>>r;
		int ans=INF;
		for (int i=1; i<=cnt[l]; i++)
		{
			for (int j=1; j<=cnt[r]; j++)
			{
				ans=min(ans,sub[l][i].d+dis[sub[l][i].x][sub[r][j].x]+sub[r][j].d);
			}
		}
		cout<<a[l]+ans+a[r]<<"\n";
	}
	return 0;
}

