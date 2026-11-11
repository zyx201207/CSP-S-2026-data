#include<bits/stdc++.h>
using namespace std;
long long a[500005],x[500005],m;
int xfind(int l,int r)
{
	int k=r;
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(a[k]*1ll*(k-mid+1)-(x[k]-x[mid-1])>m)
			l=mid+1;
		else
			r=mid-1;
	}
	return l;
}
int main()
{
//X X XXX xterfusion
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		x[i]=x[i-1]+a[i];
		ans=max(ans,i-xfind(1,i)+1);
	}
	cout<<ans;
	
}
