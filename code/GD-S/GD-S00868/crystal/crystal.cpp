#include<iostream>
#include<cmath>
#include<algorithm>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn=500005;
ll n,m,a[maxn],c[maxn],sum[maxn],sum1[maxn],b[maxn],ans=0,maxx[maxn];
inline ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-') f=-1;
		c=getchar(); 
	}
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
inline void write(ll x)
{
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
inline bool check1()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i) return false;
	}
	return true;
}
inline bool check2()
{
	ll x=a[2]-a[1];
	for(int i=2;i<=n-1;i++)
	{
		if(a[i+1]-a[i]!=x) return false; 
	}
	return true;
}
inline void fre()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
int main()
{
	IOS
	fre();
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		c[i-1]=a[i]-a[i-1];
	}
	for(int i=1;i<=n-1;i++)
	{
		sum[i]=sum[i-1]+c[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		sum1[i]=sum1[i-1]+sum[i];
	}
	for(int i=1;i<=n;i++)
	{
		ll x=0,len=1;
		for(int j=i-1;j>=1;j--)
		{
			x+=a[i]-a[j];
			if(x<=m) len++;
			else break;
		}
		ans=max(ans,len);
	}
	cout<<ans;
	return 0;
} 
