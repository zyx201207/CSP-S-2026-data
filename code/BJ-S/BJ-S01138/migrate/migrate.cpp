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
ll n,d,mi=1e18,cnt=0,a[2000005];
void dfs(ll s,ll t,ll ct)
{
	if(s==t)
	{
		if(mi==ct)cnt++;
		else if(mi>ct)mi=ct,cnt=1;
		return ;
	}
	ll p=s+1;
	while(a[p]-a[s]<=d&&p<=t)
	{
		dfs(p,t,ct+1);
		p++;
	}
}
void sol1()
{
	ll ans=0;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(i!=j)
	{
		cnt=0;
		mi=1e18;
		dfs(min(i,j),max(j,i),0);
		if(cnt==2)ans++;
	}
	out(ans,'\n');
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("hub1.in","r",stdin);
//	freopen("hub.out","w",stdout);
	ll c=in(),t=in();
	while(t--)
	{
		n=in(),d=in();
		for(int i=1;i<=n;i++)a[i]=in();
		sol1();
	}
	return 0;
}
//0 2
//4 2
//1 2 3 4 
//5 2
//1 2 3 4 5
