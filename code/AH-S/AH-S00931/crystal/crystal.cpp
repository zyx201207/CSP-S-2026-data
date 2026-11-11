#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ave,a[500005],sum,ans,av;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i]; sum += a[i];
	}
	ave = sum/n;
	sort(a+1,a+1+n);
	av = lower_bound(a+1,a+1+n,ave)-a;
	int k = av;
	for(int i = av; i <= n; i++)
	{
		if(a[i] == a[av])
		    {
			  ans++;
			  k++;
			}
	}
	for(int j = av-1; j >= 1; j--)
	{
		if(a[av] - a[j] <= m)
		{
			ans++;
			m -= a[av]-a[j];
		}
		else
			break;
	}
	
	for(int i = k+1; i <= n; i++)
	{
		if((a[i] - a[i-1]) * ans <= m)
		{
			m -= (a[i] - a[i-1]) * ans;
			ans++;
			k++;
		}
		else
			break;
	}
	cout << ans;
	
	return 0; 
}
