#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],sum[N];
int read()
{
	long long s=0,flag=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')flag=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*flag;
}
void write(long long x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
	}
	else
	{
		if(x>9)write(x/10);
		putchar(x%10+'0');
	}
}
//n saoyibian
//log n erfen
int ans=INT_MIN;
long long cnt,last,id;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=0,r=i-1;
		cnt=0;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			cnt=a[i]*mid-sum[i-1]+sum[i-mid-1];
			if(cnt<=m)l=mid;
			else r=mid-1;
			
		}
		int t=l+1;
		ans=max(ans,t);
		
	}
	write(ans);
	return 0;
}
