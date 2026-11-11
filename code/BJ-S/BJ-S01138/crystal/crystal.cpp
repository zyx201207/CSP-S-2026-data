#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll printnumber[105];
inline ll in()
{
	ll ans=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')f=(ch=='-'?-1:1),ch=getchar();
	while(ch>='0'&&ch<='9')ans=ans*10+ch-48,ch=getchar();
	return ans*f;
}
inline void out(ll x,char y)
{
	ll tot=0;
	if(x<0)putchar('-'),x=-x;
	do
	{
		printnumber[++tot]=x%10;
		x/=10;
	}while(x);
	while(tot)putchar(printnumber[tot--]+'0');
	putchar(y);
	return ;
}
ll n,m,head=1,tail=0,sum=0,ans=1,a[500005],s[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=in(),m=in();
	for(int i=1;i<=n;i++)a[i]=in();
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
	{
		if(a[i]-a[i-1]>m)break;
		sum+=(tail-head+1)*(a[i]-a[i-1]);
		s[++tail]=a[i];
		while(sum>m&&head<=tail)sum-=a[i]-s[head++];
		ans=max(ans,tail-head+1);
	}
	out(ans,' ');
	return 0;
}
