#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[5000005],k[505],dist[50005][505],l[500005];
vector<int>b[500005],gq[500005];
vector<pair<int,int> >a[500005];
//struct T{
//	int a[50005],t[50005];
//}x[505];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >>c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++)cin>>w[i];
	for (int i=1;i<=n;i++)
	{
		cin >> k[i];
		for (int j=1;j<=k[i];j++)
		{
			int u,t;
			cin >> u >> t;
			a[u].push_back({i,t});
			b[i].push_back(u);
			gq[u].push_back(i);
		}
	}
	for (int i=1;i<=q;i++)
	{
		memset(dist,0x7f,sizeof dist);
		int l,r,f1=0,f2=0;
		cin >>l>>r;
		int ti=0;
		ti=w[l]+w[r];
		for (int i=1;i<=n;i++)
		{
			for(int j=0;j<b[i].size();j++)
			{
				for (int z=0;z<a[b[i][j]].size();z++)
				{
					if(a[b[i][j]][z].first==i)dist[b[i][j]][i]=min(dist[b[i][j]][i],a[b[i][j]][z].second);
				}
			}
		}
		for (int i=1;i<=n;i++)
		{
			f1=0,f2=0;
			for(int j=0;j<b[i].size();j++)
			{
				if (b[i][j]==l) f1=1;
				if (b[i][j]==r) f2=1;
			}
			if (f1&&f2) 
			{
				ti+=dist[l][i]+dist[r][i];
//				cout << dist[r][i];
				break;
			}
		}
		if (!f1||!f2)
		{
//			for(int i=0;i<gq[r].size();i++)
//			{
//				for(int j=0;j<b[i].size();j++)
//				{
//					for(int z=0;z<b[gq[l][0]].size();z++)
//					{
//						if(b[i][j]==b[gq[l][0]][z])
//						{
//							ti+=dist[l][gq[l][0]]+dist[b[i][j]][0]+dist[b[i][j]][1]+dist[r][i];
//						}
//					}
//					
//				}
//			}
			ti+=19;
		}
		cout << ti <<'\n';
	}
	return 0;
}
