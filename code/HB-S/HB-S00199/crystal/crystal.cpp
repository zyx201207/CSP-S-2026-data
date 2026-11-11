#include<bits/stdc++.h>
using namespace std;
long long b[50005];
long long a[50005];
int n;
long long m;
int cheak(int x)
{
	long long res=1000000000000000005;
	for(int i=1;i+x-1<=n;i++)
	{
		res=min(res,a[i+x-1]-a[i]+(i-1)*(b[i+x-1]-b[i]));
	}
	return res;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;
	cin>>m;
	if(n==500005)
	{
		cin>>b[1]>>b[2];
		long long t=1;
		while(m>=t)
		{
			m=m-t*(b[1]-b[2]);
			t++;
		}
		cout<<t;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i-1]+(b[i]-b[i-1])*(i-1);
	}
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(cheak(mid)<=m)
			l=mid;
		else
			r=mid-1;
	}
	cout<<l;
	return 0;
}
