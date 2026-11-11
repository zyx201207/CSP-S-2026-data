#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')
		{x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=2e5+7;
int n;
ll sum=0,cnt=0,ans=0,sun=0;
int a[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int i,j;
	n=read();
	for(i=1;i<=n;i++)
	{
		a[i]=read();
		cin>>c[i];
		sum+=a[i];
	}
	sum/=2;
	for(i=1,j=n;i<=n;i++)
	{
		cnt+=a[i];
		while(j>=i)
		{
			if(c[j]!=c[i])
			{
				if(a[j]<=a[i])
					ans+=a[j];
				else
				{
					ans+=a[i];
					a[j]-=a[i];
					break;
				}
			}
			else if(a[j]>a[i])
			{
				a[j]-=a[i];
				break;
			}
			a[i]-=a[j];
			j--;
		}
	}
	printf("%lld",ans);
	return 0;
}
