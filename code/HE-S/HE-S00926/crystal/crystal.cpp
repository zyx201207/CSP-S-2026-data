#include<bits/stdc++.h>
using namespace std;
long long a[1000000000000],s[10101010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
	
		for(int j=i;j>=1;j--)
		{
			if(m>=a[i]-a[j-1])
			{
				m-=(a[n]-a[j-1]);
				a[j-1]=a[n];
		         s[j]++;
			}
		}
	}
	for(int i=1;i<=n+10;i++)
	{
	ans=max(s[i],ans);
	}
 cout<<ans+1;
 return 0;
}


