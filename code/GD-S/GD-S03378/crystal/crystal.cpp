#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],ans;
void read(long long &x)
{
	x=0;
	int w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') w=-1; 
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=w;
}
void write(long long x)
{
	if(x<0) putchar('-'),x=-x;
	int top=0,sta[100];
	do{
		sta[top++]=x%10,x/=10;
	}while(x);
	while(top--) putchar(sta[top]+'0');
	putchar('\n');
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	
	long long l=1;
	for(int i=1;i<=n;i++)
	{
		while((i-l+1)*a[i]-(sum[i]-sum[l-1])>m) l++;
		ans=max(ans,i-l+1);
	}
	write(ans);
	return 0;
 } 
