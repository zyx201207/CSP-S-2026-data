#include<bits/stdc++.h>
using namespace std;
long long n,m,key,t=1,maxx=-1,ans,sum;
long long a[500010],b[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long m1=m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	while(t<=n)
	{
		ans=0,m1=m,sum=0;
		for(long long i=1;i<=t;i++)
		{
			key=a[t];
			b[i]=a[i]-a[t];
		}
		for(long long i=1;i<=t;i++)
		{
			if(b[i]<0||b[i]==0)
			{
				ans++;
				sum+=b[i];
			}
		}
		if(sum+m>=0)
		{
			if(ans>maxx)
			{
				maxx=ans;
			}
		}t++;
	}
	cout<<maxx;
	return 0;
}