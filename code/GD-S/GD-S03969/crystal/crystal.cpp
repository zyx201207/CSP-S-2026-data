#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],s[500005];
long long n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
		s[i]=s[i-1]+b[i];
	}
	long long sum=0;
	long long ans=0;
	for(long long l=1,r=1;l<=n;l++)
	{
		sum-=b[l]+s[r]-s[l];
		while(l>r) r++;
		while(r+1<=n&&sum+b[r+1]*(r+1-l)<=m) sum+=b[r+1]*(r+1-l),r++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}
