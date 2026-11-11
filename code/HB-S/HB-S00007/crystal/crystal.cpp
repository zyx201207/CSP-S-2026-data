#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,need=0,sum=0,last=1,ans=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=(a[i]-a[i-1])*(i-1);
	}
	for(int i=1;i<=n;i++)
	{
		need+=b[i]-(a[i]-a[i-1])*(last-1);
		sum+=1;
		while(need>m)
		{
			sum-=1;
			need-=a[i]-a[last];
			last+=1;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
    return 0;
}
