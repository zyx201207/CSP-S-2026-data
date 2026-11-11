#include<bits/stdc++.h>
using namespace std;
#define int long long
	int n,m;
	const int N=5e5+10;
	int a[N];
	int dp[N];
	int max_n=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int cz;
	int flag=0;
	if(n==1)
	{
		flag=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			cz=a[i+1]-a[i];
		}
		else if(a[i]-a[i-1]!=cz)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		for(int i=cz;1;i+=cz)
		{
			if(m>=i)
			{
				max_n++;
				m-=i;
			}
			else
			{
				cout<<max_n;
				break;
			}
		}
	
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			int cnt=1;
			int k=m;
			for(int j=i-1;j>=1;j--)
			{
				if(k-(a[i]-a[j])>=0)
				{
					cnt++;
					k-=(a[i]-a[j]);
				}
				else
				{
					break;
				}
			}
			max_n=max(max_n,cnt);
		}
		cout<<max_n;
	}
	return 0;
}
