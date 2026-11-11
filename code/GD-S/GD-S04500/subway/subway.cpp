#include <bits/stdc++.h>
using namespace std;
long long ans;
const int N = 5e5 + 5;
int w[N],t[505][N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		for (int j = 1;j <= k;j++)
		{
			int posi;
			cin >> posi;
			cin >> t[i][posi];
		}
	}
	while(q--)
	{
		int yi,er;
		cin >> yi >> er;
		ans = w[yi] + w[er];
		if (n <= 3)
		{
			int res = 1e9;
			for (int i = 1;i <= n;i++)
			{
				if (t[i][yi] > 0 && t[i][er] > 0) res = min(res,t[i][yi] + t[i][er]);
			}
			for (int i = 1;i <= m;i++)
			{
				if (t[1][i] > 0 && t[2][i] > 0) res = min(res,t[1][i] + t[2][i] + t[1][yi] + t[2][yi] + t[1][er] + t[2][er]);
			}
			ans += res;
			cout << ans << "\n";
		}
		else if (c >= 7 && c <= 11)
		{
			if (yi > er) swap(yi,er);
			for (int i = yi;i < er;i++) ans += t[i][i] + t[i][i + 1];
			cout << ans << "\n";
		}
	}
	
	return 0;
}
