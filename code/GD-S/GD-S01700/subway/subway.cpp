#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll c,n,m,d,q;

ll w[500005];
ll a[505],t[505];
ll dis[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	
	for(ll i = 1;i <= m;i++)
		cin >> w[i];
		
	memset(dis,0x3f,sizeof(dis));
	for(ll i = 1;i <= n;i++)
	{
		ll tot;
		cin >> tot;
		for(ll j = 1;j <= tot;j++)
		{
			cin >> a[j] >> t[j];
		}
		
		for(ll j = 2;j <= tot;j++)
		{
			for(ll k = 1;k < j;k++)
			{
				dis[a[k]][a[j]] = dis[a[j]][a[k]] = t[k] + t[j];
				//cout << a[k] << a[j] << " " << dis[a[k]][a[j]] << endl;

			}
		}
	}	

	for(ll k = 1;k <= m;k++)
		for(ll i = 1;i <= m;i++)
			for(ll j = i;j <= m;j++)
			{					
				if(dis[i][k] + dis[k][j] < dis[i][j])
				{
					dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
					//cout << i << " " << j << " " << k << " " << dis[i][k] << " " << dis[k][j] << " " << dis[i][j] << endl;

				}
			}
	
	/*
	0 2 5 20 99999
	4 1 9 2 5
	3 1 5 2 7 4 6
	3 2 3 3 4 5 7
	1 3
	1 2
	
	
	*/
	while(q--)
	{
		ll x,y;
		cin >> x >> y;
		cout << w[x] + w[y] + dis[x][y] << '\n';
	}
	
	return 0;
}
