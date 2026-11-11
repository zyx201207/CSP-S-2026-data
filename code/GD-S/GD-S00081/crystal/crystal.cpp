//T1 26/10/31 1430-1530
#include<bits/stdc++.h>
using namespace std;

const long long N = 500010; 
long long ans = 0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m,mid,t;
	long long a[N];
	cin>>n>>m;
	for(long long i = 0;i < n;i++)
	{
		cin>>a[i];
	}
	if(n % 2 == 0)
	{
		t = (n / 2) - 1; 
	}
	else
	{
		t = (n / 2);
	}
	long long b[N];
	for(long long i = 0;i < n;i++)
	{
		b[i] = a[i];
	}
	sort(b,b + n);
	mid = b[t];
	for(long long i = 0;i < n;i++)
	{
		a[i] -= mid;
	}
	sort(a,a + n);
	for(long long i = 0;i < n;i++)
	{
		if(abs(a[i]) <= m && a[i] != 0 && m >= 0)
		{	
			m -= abs(a[i]);
			a[i] = 0;
		}
	}
	for(long long i = 0;i < n;i++)
	{
		if(a[i] == 0)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
