#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500005;
ll a[N],n,m,i,ans,sum[N],s[N],b[N],l,r,mid;
ll check(ll x)
{
	if((sum[x] - sum[i - 1] - (s[x] - s[i - 1]) * (i-1)) <= m)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.ont","w",stdout);
	cin>>n>>m;
	for(i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	sort(a + 1,a + 1 + n);
	for(i = 2;i <= n;i++)
	{
		b[i] = a[i] - a[i - 1];
	}
	for(i = 2;i <= n;i++)
	{
		sum[i] = sum[i - 1] + (i - 1) * b[i];
		s[i] = s[i - 1] + b[i];
	}
	for(i = 1;i<= n;i++)
	{
		l = i;r = n;
		while(l <= r)
		{
			mid = (l + r) / 2;
			if(check(mid))
			{
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			} 
		}
		ans = max(ans,(r - i + 1));
		
	}
	cout<<ans<<endl;
}
