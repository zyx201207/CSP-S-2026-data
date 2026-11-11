#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;//Oct31==Dec25?
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x*=10,x+=ch-'0';
		ch=getchar();
	}
	return x*f;
}
int a[500861];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=-1,head=1,tail=1,m1=0;
	n=read(),m=read();
	m1=m;
	for(int u=1;u<=n;u++)
	a[u]=read();
	sort(a+1,a+n+1);
	head=1,tail=0;
	a[0]=a[1];
	for(int u=1;u<=n;u++)
	{
		tail++;
		m-=(tail-head)*(a[u]-a[u-1]);
		while(m<0)
		m+=a[tail]-a[head],head++;
		ans=max(ans,tail-head+1);
	}
	cout<<ans<<endl;
	return 0;
}
