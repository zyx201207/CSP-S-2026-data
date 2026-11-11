#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500010];
long long b[500010];
long long s[500010];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
		s[i]=s[i-1]+b[i];
	}
	long long l=1,r=1;
	long long sum=0,ans=0,cnt=0;
	for(;r<=n;r++,cnt++)
	{
		sum+=b[r]*cnt;
		while(sum>m)
		{
			sum-=s[r]-s[l];
			l++;
			cnt--;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}
