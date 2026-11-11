#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long 
using namespace std;
char buf[1<<20],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
int readint()
{
	int k=0,f=1,c=gc();
	for(;!isdigit(c);c=gc())
		if(c=='-') f=-1;
	for(;isdigit(c);c=gc())
		k=(k<<3)+(k<<1)+(c^48);
	return k*f;
}
const int N=5e5+10;
int n,m,a[N],ans=1;
int s[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=readint(),m=readint();
	for(int i=1;i<=n;i++)
		a[i]=readint();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i]; 
	int l=1;
	for(int r=1;r<=n;r++)
	{
		while(a[r]*(r-l)-s[r-1]+s[l-1]>m)
			l++;
		ans=max(ans,r-l+1);
	}
	printf("%lld",ans);
}
