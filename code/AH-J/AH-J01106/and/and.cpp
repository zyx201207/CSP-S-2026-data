#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],ans=-1,maxn=-1,he;
int main()
{
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		maxn=max(maxn,a[i]);
	}
	
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	if(m==2 && n<=2000)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[i]==a[j])
				{
					ans=max(ans,a[i]);
				}
				else 
				{
					ans=max(ans,a[i]&a[j]);
				}
			}		
		}
	cout<<ans;
	return 0;
	}
	if(m==n)
	{
		for(int i=2;i<=n;i++)
		{
			a[i]=a[i]&a[i-1];
		}
		cout<<a[n];
		return 0;
	}
	else
	{
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	return 0;
}
