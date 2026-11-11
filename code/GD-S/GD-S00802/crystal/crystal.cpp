#include<bits/stdc++.h>


using namespace std;

long long n,m,a[1000000],ans = -1,flag = 1;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])
		{
			flag = 0;
		}
	}
	if(flag)
	{
		long long k = a[n] - a[n-1];
		long long ans = 0;
		while(1&&ans<=n)
		{
			if(ans*(k+ans*k)/2<=m)
			{
				ans++;
			}
			else
			{
				break;
			}
		}
		cout<<ans;
	}
	else
	{
		sort(a+1,a+n+1);
		for(int i = 1;i<=n;i++)
		{
			long long now = i,l = m;
			while(1&&now<n)
			{
				if(l>=(a[now+1]-a[now])*(now+1-i))
				{
					l-=(a[now+1]-a[now])*(now+1-i);
					now++;
				}
				else
				{
					break;
				}
			}
			ans = max(ans,now-i+1);
		} 
		
		cout<<ans;
	}
}
