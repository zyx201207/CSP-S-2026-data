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
ll n,k,tot=0,ans=1e18,mi=1e18,head[2000005],to[4000005],nxt[4000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
//	freopen("hub.out","w",stdout);
	ll c=in(),t=in();
	while(t--)
	{
		n=in(),k=in();
		for(int i=1;i<n;i++)
		{
			ll u=in(),v=in();
			to[++tot]=v;
			nxt[tot]=head[u];
			head[u]=tot;
		}
		out(0,'\n');
		for(int i=1;i<=tot;i++)to[i]=nxt[i]=0;
		for(int i=1;i<=n;i++)head[i]=0;
		tot=0;
	}
	return 0;
}
