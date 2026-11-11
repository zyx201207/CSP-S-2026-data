#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,x[2000005],f[5005][5005],cnt[5005][5005],ans;
bool flaga = true;
void floyd()
{
	for (int i = 1;i <= n;i++)
		for (int j = i + 1;j <= n;j++)
			for (int k = i;k <= j;k++)
			{
				if (i == j || j == k || i == k)
					continue;
				if (f[i][j] > f[i][k] + f[j][k])
					cnt[i][j] = 1,f[i][j] = f[i][k] + f[j][k];
				else if (f[i][j] == f[i][k] + f[j][k])
					cnt[i][j]++;
			}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
		{
			cin >> x[i];
			if (i > 2)
				if (x[i] - x[i - 1] != x[i - 1] - x[i - 2])
					flaga = false;
		}
		if (flaga)
		{
			ll diff = x[2] - x[1];
			ll k = d / diff;
			if (k <= 1 || n - 2 * k + 1 <= 0)
				cout << 0 << endl;
			else
				cout << (n - 2 * k + 1) << endl;
		}
		else if (n <= 5000)
		{
			memset(f,0x3f,sizeof(f));
			queue<int> q;
			for (int i = 1;i <= n;i++)
			{
				if (i == 1)
				{
					q.push(i);
					continue;
				}
				while (!q.empty() && x[q.front()] + d < x[i])
					q.pop();
				if (!q.empty())
					for (int j = q.front();j < i;j++)
						f[j][i] = f[i][j] = 1;
				q.push(i);
			}
//			for (int i = 1;i <= n;i++)
//			{
//				for (int j = 1;j <= n;j++)
//					cout << ((f[i][j] == 0x3f3f3f3f3f3f3f3f) ? -1 : f[i][j]) << " ";
//				cout << endl;
//			}
			floyd();
//			cout << endl;
//			for (int i = 1;i <= n;i++)
//			{
//				for (int j = 1;j <= n;j++)
//					cout << ((f[i][j] == 0x3f3f3f3f3f3f3f3f) ? -1 : f[i][j]) << " ";
//				cout << endl;
//			}
//			for (int i = 1;i <= n;i++)
//			{
//				for (int j = 1;j <= n;j++)
//					cout << cnt[i][j] << " ";
//				cout << endl;
//			}
			for (int i = 1;i <= n;i++)
				for (int j = 1;j <= n;j++)
					if (cnt[i][j] == 2)
						ans++;
			cout << ans << endl;
		}
	}
	return 0;
}
/*
0 1
6 2
-4 -3 -2 -1 3 6
*/
