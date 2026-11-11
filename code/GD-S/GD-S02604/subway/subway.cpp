#include <iostream>
using namespace std;

int w[50005] = {};

int k[505] = {};

int a[505][50005] = {};
int t[505][50005] = {};
int c, n, m, d, q;
bool z[505][50005] = {};
bool flag[505][50005] = {};

long long minn = 2147483647;

void dfs(int now, int aim, int time)
{
	cout << "now:" << now << " time:" << time;
	if(time > minn) return ;
	if(now == aim)
	{
		if(time < minn) minn = time;
		return ;
	}
	for(int i = 1; i <= n; i++)
	{
		if(z[i][now] == 1 && flag[i][now] == false)
		{
			for(int j = 1; j <= k[i]; j++)
			{
				flag[i][now] = true;
				flag[i][j] = true;
				cout << " t[" << i << "][" << j << "]:" << t[i][j] << " t[" << i << "][now]:" << t[i][now] << endl; 
				dfs(a[i][j], aim, time + t[i][j] + t[i][now]);
				flag[i][j] = false;
			}
		}
	}
	return ;
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
			z[i][a[i][j]] = 1;
			cout << " t[" << i << "][" << j << "]:" << t[i][j] << endl; 
		}
	}
	for(int num = 1; num <= q; num++)
	{
		int x, y;
		cin >> x >> y;
		minn = 2147483647;
		dfs(x, y, 0);
		cout << minn + w[x] + w[y] << endl;	
	}
	return 0;
}
