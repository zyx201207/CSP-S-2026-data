#include <bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y)
{
	return x < y;
}
long long a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	long long m;
	cin >> n >> m;
	for (long long i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1,cmp);
	long long ans = 0,maxn = 0;
	long long res = m;
	if (m == 0)
	{
		int r=0,cnt = 1,maa = 0;
		for (int i = 2;i <= n;i++)
		{
			if (a[i] == a[i-1])
			{
				r=1,cnt++;
			}
			else
			{
				r = 0;
				if (cnt > maa) maa = cnt;
				cnt = 1;
			}
		}
		cout << maa;
		return 0;
	}
	for (long long j = n;j >= 1;j--)
	{	
		ans = 0,res = m;
		if (j <= (maxn+1))
			break;
		for (long long i = j-1;i >= 1;i--)
		{
			/*if (a[i] == a[j])
			{
				ans++;
				continue;
			}*/
			res -= a[j]-a[i];
			if (res < 0) break;
			ans++;
		}
		
		if(ans > maxn) maxn = ans;
	}
	cout << maxn + 1;
	return 0;
 } 
