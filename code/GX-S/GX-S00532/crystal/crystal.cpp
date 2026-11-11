#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],ans;
bool check(int mid)
{
	long long now=m;
	bool f=true;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[mid])
			break;
		if(now<(a[mid]-a[i]))
		{
			f=false;
			break;
		}
		now-=(long long)a[mid]-a[i];
	}
	return f;
}
long long num(int mid)
{
	long long now=m,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[mid])
			break;
		if(now>=(a[mid]-a[i]))
		{
			now-=(long long)a[mid]-a[i];
			 cnt++;
		}
	}
	return cnt;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid+1;
			ans=max(ans,num(mid));
		}
		else
		{
			ans=max(ans,num(mid));
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
