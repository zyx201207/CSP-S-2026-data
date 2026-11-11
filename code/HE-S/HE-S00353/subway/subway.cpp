#include<bits/stdc++.h>
using namespace std;
long long m,n;
const int N=500005;	
long long a[N];
long long qz[N] = {0};//Ç°×ººÍ 
long long maxx = 0;
int f(long long l,long long r)
{
	if(l==r)
	{
		return l;
	}
	long long mid = (l+r)/2;
	if((qz[mid]-qz[l-1]+m)/a[mid] >= mid-l+1)
	{
		return f(mid,r);
	}
	else
	{
		return f(l,mid-1);
	}
}
int main()
{
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		qz[i] = a[i]+qz[i-1];
	}
	sort(a+1,a+n+1);
	
	for(long long i=1;i<=n;i++)
	{
		int z = f(i,n);
		maxx=max(maxx, z - i + 1);
	}
	cout<<maxx;
	return 0;
}
