#include<bits/stdc++.h>
using namespace std;
long long n,m,gr,x;
const int qwe=5e5+3;
long long a[qwe],b[qwe];
void work1()
{
	cout<<n;
}

bool check(long long w)
{
	if(w*(w+1)<=x)return 1;
	return 0;
}
int erfen()
{
	long long l=1,r=1e9;
	while(l<=r)
	{
		long long mid=l+r>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	return r;
}
void work2()
{
	long long d=a[2]-a[1];
	x=m*2/d;
	cout<<erfen()+1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	int g=0;//teshustart
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[1])g++;
	}
	if(g==n)
	{
		work1();
		return 0;
	}
	int r=0;
	for(int i=1;i<n;i++)
	{
		if(a[i+1]-a[i]==a[2]-a[1])r++;
	}
	if(r==n-1)
	{
		work2();
		return 0;
	}//teshuend
	int ans=-1;
	int mm=m;
	for(int i=1;i<=n;i++)
	{
		m=mm;
		for(int j=1;j<=n;j++)
		{
			b[j]=a[i]-a[j];
		}
		sort(b+1,b+n+1);
		int res=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]>=0)m-=b[i];
			else continue;
			if(m<0)break;
			res++;
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}
