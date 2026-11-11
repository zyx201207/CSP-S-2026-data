#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 510;
const int maxm = 5e5 + 10;
const int maxq = 1e5 + 10;
int c,n,m,d,q;
int w[maxm]; 
int xs[maxn];
int a[maxn][maxm],t[maxn][maxm];
int x[maxq],y[maxq];
vector<int> xl;
void bfs()
{
	q.push(1);
	while(!q.empty())
	{
		
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin >> xs[i];
		for(int j=1;j<=xs[i];j++)
		{
			cin >> a[i][j];
			cin >> t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin >> x[r] >> y[r];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=xs[i];j++)
		{
			for(int k=1;k<=n;k++)
			{
				for(int z=1;z<=xs[k];z++)
				{
					if(a[i][j]==a[k][z])
					{
						xl[i][k] = min(xl[i][k],t[k][z]+w[a[k][z]]);
						xl[k][i] = min(xl[k][i],t[i][j]+w[a[i][j]]);
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=xs[i];j++)
		{
			for(int k=1;k<=n;k++)
			{
				for(int z=1;z<=xs[k];z++)
				{
					
				}
			}
		}
	}
	bfs();
	return 0;
}
