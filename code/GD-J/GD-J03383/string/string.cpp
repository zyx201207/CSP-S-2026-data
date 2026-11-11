#include<bits/stdc++.h>
using namespace std;
long long n,a[100001],sum,k,k1,ans; 
char c[100001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(sum%2)
	sum=sum/2+1;
	else sum/=2;
	for(int i=1;i<=n;i++)
	{
		if(sum>a[i])sum-a[i];
		else 
		{
			k=i;k1=sum;break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int b=1,b1=n;
		while(a[b]!=0)
		{
			if(c[b]==c[b1])
			{
				if(a[b]>a[b1])
				{
					a[b]-=a[b1];
					a[b1]=0;b1--;
				}
				if(a[b]==a[b1])
				{
					a[b]-=a[b1];
					a[b]=a[b1]=0;b++;b1--;
				}
				if(a[b]<a[b1])
				{
					a[b1]-=a[b];
					a[b]=0;b++;
				}
			}
			else
			{
				if(a[b]>a[b1])
				{
					ans+=a[b1];
					a[b]-=a[b1];
					a[b1]=0;b1--;
				}
				if(a[b]==a[b1])
				{
					ans+=a[b1];
					a[b]-=a[b1];
					a[b]=a[b1]=0;b++;b1--;
				}
				if(a[b]<a[b1])
				{
					ans+=a[b];
					a[b1]-=a[b];
					a[b]=0;b++;
				}
			}
		}
		if(b==b1)break;
	}
	cout<<ans;
	return 0;
}
