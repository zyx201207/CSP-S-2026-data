#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;
int c,n,m,d,q,ans = MAXN;
int w[MAXN],a1[11],a[MAXN][4],t[MAXN][4];
bool subway[MAXN];

void dfs(int x,int y,int z,int k)
{
	if(x == y)
	{
		ans = min(ans,z + w[y] + t[y][k]);
		return;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= a[0][i] ; j++)
		{
			if(a[j][i] == x)
			{
				if(!subway[j + 1] && j + 1 <= a[0][i])
				{
					if(k != i && k != 0)
					{
						subway[j] = true;
						dfs(a[j + 1][i],y,z + t[j][i] + t[j][k],i);
						subway[j] = false;
					}
					else if(k == 0)
					{
						subway[j] = true;
						dfs(a[j + 1][i],y,z + t[j][i] + w[x],i);
						subway[j] = false;
					}
					else
					{
						subway[j] = true;
						dfs(a[j + 1][i],y,z,i);
						subway[j] = false;
					}
				}
				else if(!subway[j - 1] && j > 1)
				{
					if(k != i && k != 0)
					{
						subway[j] = true;
						dfs(a[j - 1][i],y,z + t[j][i] + t[j][k],i);
						subway[j] = false;
					}
					else if(k == 0)
					{
						subway[j] = true;
						dfs(a[j - 1][i],y,z + t[j][i] + w[x],i);
						subway[j] = false;
					}
					else
					{
						subway[j] = true;
						dfs(a[j - 1][i],y,z,i);
						subway[j] = false;
					}
				}
			}
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i++)
		cin >> w[i];
		
	if(n == 1)
	{
		int k;
		cin >> k;
		for(int i = 1 ; i <= k ; i++)
		{
			int x,y;
			cin >> x >> y;
			a1[x] = y;
		}
		for(int i = 1 ; i <= q ; i++)
		{
			int x,y;
			cin >> x >> y;
			cout << w[x] + w[y] + a1[x] + a1[y] << endl;
		}
	}
	else
	{
		for(int i = 1 ; i <= n ; i++)
		{
			int k;
			cin >> k;
			for(int j = 1 ; j <= k ; j++)
			{
				cin >> a[j][i] >> t[j][i];
				a[0][i] = k;
			}
		}
		for(int i = 1 ; i <= q ; i++)
		{
			ans = 500005;
			int x,y;
			cin >> x >> y;
			dfs(x,y,0,0);
			cout << ans << endl;
		}
	}
	return 0;
}
