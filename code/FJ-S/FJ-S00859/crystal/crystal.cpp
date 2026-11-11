#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[2000010],ma;
void ss(long long x,long long y,long long k)
{
	if(x==y)
	{
		b[k]=a[x];
		return;
	}
	long long mid=(x+y)>>1;
	ss(x,mid,k<<1);
	ss(mid+1,y,(k<<1)+1);
	b[k]=b[k<<1]+b[(k<<1)+1];
}
long long cc(long long l,long long r,long long x,long long y,long long k,long long s)
{
	if(l<=x&&y<=r)
	{
		return (y-x)*s-b[k];
	}
	long long mid=(x+y)/2,nm=0;
	if(l<mid)
	{
		nm+=cc(l,r,x,mid,k<<1,s);
	}
	if(mid<r)
	{
		nm+=cc(l,r,mid,y,(k<<1)+1,s);
	}
	return nm;
}
int main()
{
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ss(1,n,1);
	for(long long i=1;i<=n;i++)
	{
		long long l=1,r=i-1,w=0;
		while(r>=l)
		{
			long long mid=(l+r)/2;
			long long s=cc(mid,i-1,1,n,1,a[i]);
			if(s<m)
			{
				r=mid-1;
				w=max(w,i-mid+1);
			}
			else
			{
				l=mid+1;
			}
		}
		ma=max(ma,w);
	}
	cout<<ma;
	return 0;
}
