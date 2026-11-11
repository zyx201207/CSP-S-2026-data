#include<bits/stdc++.h>
using namespace std;
long long n,k,u,a[1000005],a2[100005];

long long id,s[100005],max2,ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a2[i];
		long long j=1;
		for(;j<=a2[i];j*=2)
		{
			if((a2[j]&j)==j)
			{
				a[i]++;
			}
		}
		max2=max(j/2,max2);
	}
	for(long long i=max2;i>=1;i--)
	{
		if(a[i]>=k)
		{
			max2=i;
			break;
		}
	}
	for(long long i=1;i<=n;i++)
	{
		if((a2[i]&max2)==max2)
		{
			s[++id]=a2[i];
			if(ans==0)ans=a2[i];
			else ans=(ans&a2[i]);
			if(id==k)break;
		}
	}
	cout<<ans;
	return 0;
}
