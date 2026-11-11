#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 205;
int c, n, m, d ,q;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//最短路
	cin >> c >> n >> m >> d >> q;
	int w[N];
	for(int i = 1;i <= m ;i++)
	{
		cin >> w[i];
	}
	int k, a[N][N], t[N][N];
	for(int i = 1;i <= n; i++)
	{
		cin >> k;
		for(int j = 1;j <= k; j++)
			cin >> a[i][j] >> t[i][j];//i 列车编号, j 下标
			 
	}
	int x, y;
	
	for(int i = 1 ;i <= q; i++)
	{
		int ans_time = 0, all_t = 1e9;
		cin >> x >> y;
		ans_time = w[x] + w[y] + t[i][x] + t[i][y];
		all_t = min(all_t, ans_time);
		cout << all_t << '\n'; 
	}
	return 0;
	//啊,帮帮我吧,评测机大人 
}
