#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i128 __int128
int const N = 2e6;
ll n, d, x[N], c ,t, ans = 0, cnt, dis[N];
int main()//O(t * T(n)) T(n)子问题 = O(n ^ 2)的时候可以过 
{ 								//但大样例没过 且O(n ^ 3) 
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		ans = 0;
		for(int i = 1;i <= n;i++)
			cin >> x[i];
		for(int l = 1;l < n;l++)
		{
			dis[l] = 0;
			for(int r = l + 1;r <= n;r++)
			{
				if((i128)x[r] - x[r - 1] > d)
					break;
				int i = r;
				for(;i > l;i--)
					if((i128)x[r] - x[i - 1] > d)
						break;
				dis[r] = dis[i]+1;
//				cout << l << " " << r << " to " << i <<
// 				" dis " << dis[r] << "\n";
				cnt = 0;
				for(;i < r;i++)
				{
					if(dis[i] == dis[r] - 1)
						cnt += 1;
					else
						break;
				}
//				cout << " " << cnt << " at end\n";
				if(cnt == 2)
					ans++;
		}
		}
		cout << ans << "\n";
	}
	return 0;
 } 
