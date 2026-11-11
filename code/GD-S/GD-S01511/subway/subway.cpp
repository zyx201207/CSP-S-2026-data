#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k,a, t, x,fa[500005];
vector<pair<int,int>>g[10005], st[500005];
int main()
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> c;
	while(c--)
	{
		cin >> n >> m >> d >> q;
		for(register int i=0;i<=1000005;i++)
			g[i].clear();
		for(register int i=1;i<=m;i++)
		{
			cin >> w[i];
		}
		t=n;
		for(register int i=1;i<=n;i++)
		{
			cin >> k;
			for(register int j=1;j<=k;j++)
			{
				cin >> a >> x;
				st[a].push_back({i,x})
				if(!fa[a])fa[a]=i;
				else
				{
					if(fa[a]<=n)
					{
						g[++t].push_back({i,st[a][fa[a]]});
						g[i].push_back({t,x[i][j]})
						fa[a[j]]=t;
					} 
				}
			}
		}
		
		
	}
	return 0;
}
