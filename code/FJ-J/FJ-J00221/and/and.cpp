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
int n,m;
int p=1,ans=0,cnt;
int a[N];
bool cmp(int x,int y){return x>y;}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int i,j,l,r;
	n=read();m=read();
	for(i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1,cmp);
	while(p*2<=a[1])
		p*=2;
	l=1;r=n;
	while(p)
	{
		cnt=0;i=1;
		while(a[i]<p)
			i++;
		while(a[i]>=p&&i<=r)
			a[i]-=p,cnt++,i++;
		if(cnt>=m)
			ans+=p,r=i;
		p/=2;
	}
	printf("%d",ans);
	return 0;
}
