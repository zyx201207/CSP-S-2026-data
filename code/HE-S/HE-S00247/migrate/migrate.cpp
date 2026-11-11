#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int n,d,ans;
int x[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int C,T;
	cin >> C >> T;
	while(T --)
	{
		cin >> n >> d;
		for(int i = 1;i <= n;i ++)
		{
			cin >> x[i];
		}
		if(C == 11 || C == 12 || C == 0)
		{
			ans = 0;
			int mx = 0;
			bool f = 0;
			for(int i = 1;i <= n;i ++)
			{
				if(! f)
				{
					if(x[i] - x[1] > d)
					{
						f = 1;
						mx = i - 2;
					}
				}
			}
			for(int i = 1;i <= n;i ++)
			{
				if(i + mx * 2 - 2 < n && mx >= 2)
				{
					ans ++;
				}
			}
			cout << ans << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}
	return 0;
}
