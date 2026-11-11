#include<bits/stdc++.h>
#define int __int128
using namespace std;
const int maxn=5*1e5+5;
int n,m,a[maxn],sum[maxn];
int read()
{
	int num=0,sign=1;
	char ch=getchar();
	while(ch<'0' or ch>'9')
	{
		if(ch=='-')
			sign=-1;
		ch=getchar();
	}
	while(ch>='0' and ch<='9')
	{
		num=num*10+ch-'0';
		ch=getchar();
	}
	return num*sign;
}
void print(int p)
{
	if(p<0)
		putchar('-'),p=-p;
	if(p/10)
		print(p/10);
	putchar(p%10+'0'); 
}
bool check(int p)
{
	int ans=-1;
	for(int i=p;i<=n;i++)
	{
		int tot=a[i]*p-(sum[i]-sum[i-p]);
		if(ans==-1 or tot<ans)
			ans=tot;
		if(ans<=m)
		{
			//printf("i=%d tot=%d mid=%d可以记得改\n",i,tot,p);
			return true;	
		}
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		if(!check(mid))
			r=mid-1;
		else
		{
			ans=max(ans,mid);
			l=mid+1; 
		}
	}
	print(ans);
	return 0;
}
