//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int MAXN=500005;
//int n,m,t,ans,al,ar;
//int a[MAXN];
//inline int read()
//{
//	int x=0,f=1;
//	char c=getchar();
//	while(c<'0'||c>'9')
//	{
//		if(c=='-') f=-1;
//		c=getchar();
//	}
//	while(c>='0'&&c<='9')
//	{
//		x=(x<<1)+(x<<3)+c-'0';
//		c=getchar();
//	}
//	return x*f;
//}
//int check(int pos)
//{
//	int k=a[pos],res=1,up=m;
//	for(int i=pos-1;i>=1;i--)
//	{
//		if(up>=(k-a[i]))
//		{
//			up-=(k-a[i]);
//			res++; 
//		}
//		else break;
//	}
//	return res;
//}
//signed main()
//{
////	freopen("crystal.in","r",stdin);
////	freopen("crystal.out","w",stdout);
//	n=read(),m=read();
//	for(int i=1;i<=n;i++)
//	{
//		a[i]=read();
//	}
//	sort(a+1,a+n+1);
//	int d=a[2]-a[1],f=1;
//	for(int i=3;i<=n;i++)
//	{
//		if(a[i]-a[i-1]!=d)
//		{
//			f=0;
//			break;
//		}
//	}
//	if(f)
//	{
//		int res=(sqrt(1.0+8.0*m/d)-1)/2.0;
//		printf("%lld",res+1);
//		return 0;
//	}
//	for(int i=1;i<=n;i++)
//	{
//		t=check(i);
//		if(t>ans)
//		{
//			ans=t;
//			al=i,ar=i-t+1;
//		}
//	}
//	printf("%lld",ans);
//	cout<<"\n"<<al<<" "<<ar;
//	return 0;
//}
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=500005;
int n,m,ans,mi=2e18;
int a[MAXN],s[MAXN];
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		mi=min(mi,a[i]);
	}
	sort(a+1,a+n+1);
//	int d=a[2]-a[1],f=1;
//	for(int i=3;i<=n;i++)
//	{
//		if(a[i]-a[i-1]!=d)
//		{
//			f=0;
//			break;
//		}
//	}
//	if(f)
//	{
//		int res=(sqrt(1.0+8.0*m/d)-1)/2.0;
//		printf("%lld",res+1);
//		return 0;
//	}
	if(mi<0)
	{
		for(int i=1;i<=n;i++)
		{
			a[i]-=mi;
		}
	}
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	int i=1,j=1,t=0,len=0,res=0;
	while(j<=n&&i<=n)
	{
		t=s[j]-s[i-1],len=j-i+1;
		res=a[j]*len-t;
		if(res<=m)
		{
			ans=max(ans,len);
			j++;
		}
		else
		{
			i++;
		}
	}	
	printf("%lld",ans);
	return 0;
}
