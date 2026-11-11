#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum,ans,fds;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>c[i];
	}
	fds=n;
	for(int i=1;i<=n/2;++i)
	{
		sum=a[i];
		for(int j=fds;j>i;--j)
		{
			if(sum<=0)break;
			if(c[i]!=c[j]&&sum>=a[j])
			{
				ans+=a[j];
				sum-=a[j];
				fds--;
			}
			else if(c[i]!=c[j]&&sum<a[j])
			{
				ans+=sum;
				a[j]-=sum;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
