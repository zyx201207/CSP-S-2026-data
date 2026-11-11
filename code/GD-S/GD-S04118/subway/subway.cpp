#include<bits/stdc++.h>
using namespace std;
const int N = 2010;
int c,n,m,d,q;
int a[N];
struct node{
	int to,wi;
};
vector<node> w[N];
int t[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> a[i];
		w[i].push_back({i + m,0}); // k -> t
	}
	for(int i = 1;i <= n;i++)
	{
		int k = 0;
		cin >> k;
		for(int x = 1;x <= k;x++)
		{
			int xx = 0;
			int yy = 0;
			cin >> xx >> yy;
			w[xx + m].push_back({2 * m + i,yy});
			w[2 * m + i].push_back({xx,yy});
		}
	}
	m = m * 2 + n;
	if(n <= 200)
	{
		memset(t,0x3f,sizeof(t));
		for(int i = 1;i <= m;i++)
		{
			t[i][i] = 0;
			for(node e:w[i])
			{
				t[i][e.to] = e.wi;
				//cout << i << " " << e.to << " " << e.wi << endl;
			}
		}
		for(int k = 1;k <= m;k++)
		{
			for(int i = 1;i <= m;i++)
			{
				for(int x = 1;x <= m;x++)
				{
					t[i][x] = min(t[i][x],t[i][k] + t[k][x]);
					//if(t[i][x] < 100) cout << i << " " << x << " " << t[i][x] << endl;
				}
			}
		}
		for(int i = 1;i <= q;i++)
		{
			int xx = 0;
			int yy = 0;
			cin >> xx >> yy;
			cout << t[xx][yy + (m - n) / 2] + a[xx] + a[yy] << endl;
		}
	}
//	cout << fixed << setprecision(2) << endl;
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
