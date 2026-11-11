#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,m,w[500005],n,k[505],d;
int q,x,y;
int ans;
vector<vector<int>> a(505),t(505);
int v[505][5005];

void dfs(int way,int xia,int time)
{
//	cout << 1;
	if(a[way][xia]==y)
	{
//		cout << 4;
		ans=min(ans,time);
		return;
	}
	for(int i=0;i<k[way];i++)
	{
//		cout << 2;
		if(i==xia||v[way][a[way][i]]==1)continue;
		v[way][a[way][i]]=1;
		dfs(way,a[way][i],time+t[way][xia]);
		v[way][a[way][i]]=0;
	}
	for(int i=1;i<=n;i++)
	{
//		cout << 3;
		if(way==i) continue;
		for(int j=0;j<k[i];j++)
		{
			if(a[way][xia]==a[i][j]&&v[i][j]==0)
			{
				v[i][j]=1;
				dfs(i,j,time+t[i][j]);
				v[i][j]=0;
			}
				
		}
	}
}

signed main()
{
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin >> k[i];
		for(int j=1;j<=k[i];j++)
		{
			int ina,in_t;
			cin >> ina >> in_t;
			a[j].push_back(ina);
			t[j].push_back(in_t);
		}
	}
	while(q--)
	{
		ans=LONG_LONG_MAX;
		memset(v,0,sizeof(v));
		cin >> x >> y;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<k[i];j++)
			{
				if(x==a[i][j])
				{
					v[i][j]=1;
					dfs(i,j,0);
					v[i][j]=0;
				}
			}
		}
		ans+=w[x]+w[y];
		cout << ans << "\n";
	}
	return 0;
}
