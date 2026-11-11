#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int INF=0x3f3f3f3f;
long long n,m,a[N],ans,l,r,s[N];
bool check(long long mid)
{
	long long num=INF;
	for(int i=mid;i<=n;i++)
	{
		num=min(num,a[i]*mid-(s[i]-s[i-mid]));
	}
	return num<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	l=1;r=n;	
	while(l<=r)
	{
		long long mid=l+r>>1;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	cout<<ans;
	return 0;
} 
