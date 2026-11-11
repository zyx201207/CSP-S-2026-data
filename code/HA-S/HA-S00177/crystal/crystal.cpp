#include<bits/stdc++.h>
using namespace std;
long long a[600001];
long long n,m;
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++)  scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	long long pd=1,x=a[2]-a[1];
	for(int i=2;i<n;i++)
	{
		if(a[i+1]-a[i]!=x)  
		{
			pd=0;
			break;
		}
	}
	if(pd==1)
	{
	x=a[2]-a[1];
		long long ans=1,i=1,mm=x;
	while(mm<=m&&i<n)
	{
		ans++;
		i++;
		mm+=i*x;
	}
	cout<<ans;
	return 0;
	}
	else
	{
		long long mm=0,ans=-1;
		for(int i=n,j=n;i>=1;i--)
	{
	    mm+=a[j]-a[i];
		if(mm>m)  
		{
			int k=j;
			do{
				mm-=(a[k]-a[k-1])*(k-i);
				k--;
			}while(mm>m);
			j=k;
			if(j-i+1>ans)  ans=j-i+1;
			
		}
		else
		{
			if(j-i+1>ans)  ans=j-i+1;
		}
	}
	cout<<ans;
	return 0;
	}
}
