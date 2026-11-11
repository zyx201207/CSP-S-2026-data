#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 5e5 + 10;
ll n,m;
ll a[maxn];
ll b[maxn];
ll c[maxn];
ll ans,sum;
ll cha;
bool flag;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	flag = true;
	ans = 1;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])
		{
			flag = false;
		}
		cha = a[i] - a[i-1];
	}
	if(flag)
	{
		for(int i=1;i<=n-1;i++)
		{
			sum += i * cha;
			if(sum>m)
			{
				sum -= i;
				ans = i+1;
			}
		}
	}
	else	
	{
		for(int i=1;i<n;i++)
		{
			b[i] = a[i+1] - a[i];
		}
		for(int i=1;i<n;i++)
		{
			ll cnt = 1;
			for(int j=i;j<n;j++)
			{
				c[i] += b[j] * cnt;
				if(c[i]<=m)
				{
					cnt++;	
				}
				else
				{
					c[i] -= b[j] * cnt;
					ans = max(ans,cnt);
					break;
				}
				if(j==n-1)
				{
					ans = max(ans,cnt);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
