#include <bits/stdc++.h>
using namespace std;
int c,n,m,dd,q,pop;
long long w[500005],zhuan = 999999999999999;
int k[505],a,t,x,y;
vector<int> h[505];
long long d[500005][3];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> dd >> q;
	for (int i = 1;i <= m;i++)
		cin >> w[i];
	for (int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for (int j = 1;j <= k[i];j++)
		{
			cin >> a >> t;
			h[a].push_back(i);
			d[a][i] = t;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		if (h[i].size() == 2)
		{
			zhuan = min(zhuan,d[i][1] + d[i][2]);
		}
	}
	for (int opt = 1;opt <= q;opt++)
	{
		cin >> x >> y;
		long long ans = 999999999999;
		for (int i = 0;i < h[x].size();i++)
		{
			for (int j = 0;j < h[y].size();j++)
			{
				if (h[x][i] == h[y][j])
				{
					int pop = h[x][i];
					ans = min(ans,w[x] + d[x][pop] + d[y][pop] + w[y]);
				}
			}
		}
		for (int i = 0;i < h[x].size();i++)
		{
			for (int j = 0;j < h[y].size();j++)
			{
				if (h[x][i] != h[y][j])
				{
					int popx = h[x][i],popy = h[y][j];
					ans = min(ans,w[x] + d[x][popx] + zhuan + d[y][popy] + w[y]);
				}
			}
		}
		cout << ans << endl;
	}
}
