#include<bits/stdc++.h>
#define int long long
#define fre freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout)
using namespace std;
const int MAXN=5e5+34;
int n,m,a[MAXN],sum[MAXN],l,r;
bool check(int mid)
{
	for(int i=1;i+mid-1<=n;i++) if(a[i+mid-1]*mid-sum[i+mid-1]+sum[i-1]<=m) return true;
	return false;
}
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
void write(int x)
{
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
signed main()
{
	fre,n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n),l=1,r=n;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	write(l);
	return 0;
}
