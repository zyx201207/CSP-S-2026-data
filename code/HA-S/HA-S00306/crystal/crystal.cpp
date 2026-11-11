#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*w;
}
void write(int x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	if(x>=10) write(x/10);
	putchar((x%10)^48);
}
const int N=500005;
int a[N],sum[N],n,m;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i,ans=-1;
		while(l<=r)
		{
			const int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m) r=mid-1,ans=mid;
			else l=mid+1;
		}
		int extra=upper_bound(a+i+1,a+n+1,a[i])-a-1-i;
		if(ans!=-1) maxn=max(maxn,i-ans+1+extra);
	}
	write(maxn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
