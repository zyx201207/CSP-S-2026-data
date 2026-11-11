#include <bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=(k<<3)+(k<<1)+c-'0';
		c=getchar();
	}
	return k*f;
}
long long n,m;
long long a[1000010];
bool cmp(long long aa,long long bb)
{
	return aa<bb;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1,cmp);
	long long now=1,ans=1,ggg=0;
	for(int i=2;i<=n;i++)
	{
		ggg+=(a[i]-a[i-1])*(i-now);
		while(ggg>m) ggg-=a[i]-a[now++];
		ans=max(ans,i-now+1);
	}
	printf("%lld",ans);
	return 0;
}
