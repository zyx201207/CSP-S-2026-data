#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],maxx=-1e9,t;
bool check(long long i,long long j)
{
	long long d=a[i]*(i-j)-b[i-1]+b[j-1];
	if(d<=m)
	{
		return 1;
	}
	return 0;
}
long long ef(long long i)
{
	long long l=1,r=i-1,mid;
	if(l+1==r)
	{
		if(check(i,l))
		{
			return l;
		}
		if(check(i,r))
		{
			return r;
		}
		return -1e10;
	}
	while(l+1<r)
	{
		mid=(l+r)>>1;
		if(check(i,mid))
		{
			r=mid;
			continue;
		}
		l=mid;
	}
	if(!check(i,r))
	{
		return -1e10;
	 } 
	return r;
 } 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	for(long long i=n;i>=1;i--)
	{
		long long t=1,j=ef(i);
		if(j!=-1e10)
		{
			while(check(i,j) && j>1)
			{
				j--;
			}
			if(!check(i,j))
			{
				j++;
			}
			t=i-j+1;
		}
		maxx=max(maxx,t);
	}
	cout<<maxx;
	return 0;
}
