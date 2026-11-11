#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int b[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 29;i >= 0;i--)
	{
		int cnt = 0;
		for(int j = 1;j <= n;j++)
		{
			if((a[j]>>i)&1)cnt++;
		}
		if(cnt >= m)
		{
			int tot = 0;
			for(int j = 1;j <= n;j++)
			{
				if((a[j]>>i)&1)
				{
					b[++tot] = a[j];
				}
			}
			for(int j = 1;j <= tot;j++)
			{
				a[j] = b[j];
			}
			n = tot;
			ans += (1<<i);
		}
	}
	cout << ans;
	return 0;
}
/*
1111
1100
1100
0011

11111
01111
00111
00011
00001

10111
01101
00111
00011
00001

00101
*/
