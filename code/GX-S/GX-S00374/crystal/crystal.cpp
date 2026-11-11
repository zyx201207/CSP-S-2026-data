#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,ans=1;
long long a[500010],num[200010];
long long ok(long long x)
{
	long long flag=0,t=m,sum=0;
	for(int i=1;i<=n;i++)
		if(a[i]>=x) {flag=i-1; break;}
	for(int i=flag;i>=1;i--)
		if(t>=x-a[i])
		{
			t-=(x-a[i]);
			sum++;
		}else break;
	return sum;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		num[a[i]]++;
	}
	sort(a+1,a+n+1);
	/*
		int f=((n%2==0)?(n/2):(n/2+1));
		for(int i=f-1;i>=1;i--)
			if(m>=a[f]-a[i]) m-=(a[f]-a[i]),ans++;
			else break;
		for(int i=f+1;i<=n;i++)
			if(a[i]==a[f]) ans++;
			else break;
		cout<<ans;
	*/
	/*
	long long l=a[1],r=a[n]+m;
	while(l<=r)
	{
		long long mid=r-(r-l)/2;
		long long k=ok(mid)+num[mid];
		if(k>ans) l=mid+1,ans=k;
		else r=mid-1;
	}
	*/
	for(int i=1;i<=n;i++)
		ans=max(ok(a[i])+num[a[i]],ans);
	cout<<ans;
	return 0;
}
