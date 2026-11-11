#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	bool a[m+1][n+1]={0};
	int t[m+1][n+1]={0};
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		for (int j = 1;j <= k;j++)
		{
			int r,f;
			cin >> r >> f;
			a[r][i] = 1;
			t[r][i] = f;
		}
	}
	
	int ans = 0;
	for (int i = 1;i <= q;i++)
	{
		int x,y,minn = 1e9,f = 0;
		cin >> x >> y;
		ans = w[x] + w[y];
		for (int j = 1;j <= n;j++)
		{
			if (a[x][j] == 1 && a[y][j] == 1)//Ö±´ï
			{
				ans += t[x][j] + t[y][j];
				f = 1;
			} 
			if (ans < minn) minn = ans;
		}
		int x1 = 0,y1 = 0,z = 0;
		if (f == 1)
		{
			cout << minn << endl;
			continue;
		}
		for (int j = 1;j <= n;j++)
		{
			if (a[x][j] == 1) x1 = j;
			if (a[y][j] == 1) y1 = j;
		}
		for (int j = 1;j <= m;j++)
		{
			if(a[j][x1] == 1 && a[j][y1] == 1)
				z = j;
		}
		ans += t[x][x1] + t[y][y1] + t[z][x1] + t[z][y1];
		cout << ans << endl;
	}
	return 0;
}
