#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long n,m;
long long a[N];
long long b[N];
long long ans=1;
bool f;
int p;
bool ppp(long long x,long long y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	f=1;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==2)
			p=a[2]-a[1];
		if(i>=3&&a[i]-a[i-1]!=p)
			f=0;
	}
	if(f==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(m<i*p||i==n)
			{
				cout<<i<<endl;
				return 0;
			}
			m-=i*p;
		}
		return 0;
	}
	p=1;
	sort(a+1,a+1+n,ppp);
	for(long long i=2;i<=n;i++)
	{
		long long cnt=1;
		long long o=m;
		for(long long j=i-1;j>=1;j--)
		{
			if((a[i]-a[j])>o)
			{
				break;
			}
			else
			{
				o=o-(a[i]-a[j]);
				cnt++;
				ans=max(ans,cnt);
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}
