#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long a[maxn];
long long n,m;
bool check(long long x)
{
	long long sum=0;
	for(int i=1;i<x;i++)sum+=((long long)(a[x]-a[i]));
	if(sum<=m)return 1;
	else return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long l=1,r=n;
	long long ans=0;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(check(mid))
		{
			ans=max(ans,mid);
			l=mid+1;
		}
		else r=mid-1;
	}
	long long sum=0;
	for(int i=1;i<=ans;i++)sum+=(a[ans]-a[i]);
	l=1;
	r=ans;
	long long ll=ans;
	while(1)
	{
		sum-=(a[r]-a[l]);
		l++;
		while(sum+(a[r+1]-a[r])*(r-l+1)<=m&&r<n)
		{
			sum+=(a[r+1]-a[r])*(r-l+1);
			r++;
		}
		ll=max(ll,r-l+1);
		if(r==n)break;
	}
	cout<<ll;
	return 0;
}
