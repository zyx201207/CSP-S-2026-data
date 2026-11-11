#include<bits/stdc++.h>
using namespace std;
long long t,n,m,a[500500],ans = 1,base = 1;
bool f = 1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(a[1] != a[2])
	{
		m -= a[2]-a[1];
	}
	for(int i=3;i<=n;i++)
	{
		if(m>=a[i-1]*2-a[i])
		{
			m -= a[i-1]*2-a[i];
		}
		else 
		{
			t = i;
			break;
		}
	}
	ans = t-1;
	for(int i=t+1;i<=n;i++)
	{
		if(m>=2*a[t-1]-a[i])
		{
			m -= 2*a[t-1]-a[i];
			ans++;
			t++;
		}
	}
	cout<<ans;
}
