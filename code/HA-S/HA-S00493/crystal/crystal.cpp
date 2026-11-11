#include <bits/stdc++.h>
using namespace std;
int n,a[500005],maxn,cnt,t;
long long m,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = n;j >= 1;j--)
		{
			if(a[j]-a[i] > m) continue;
			for(int x = i;x <= j;x++)
			{
				ans += (a[j] - a[x]);
				cnt++;
			}
			if(maxn < cnt && ans <= m)
			{
				maxn = cnt;
			}
			cnt = 0;
			ans = 0;
		}
		
	}
	cout << maxn;
	return 0;
}
