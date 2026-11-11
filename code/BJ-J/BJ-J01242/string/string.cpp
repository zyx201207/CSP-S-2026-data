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
inline char inc()
{
	char ch=getchar();
	while(ch<'a'||ch>'z')ch=getchar();
	return ch;
}
inline void out(ll x,char y)
{
	ll tot=0;
	if(x<0)x=-x,putchar('-');
	do
	{
		printnumber[++tot]=x%10;
		x/=10;
	}while(x);
	while(tot)putchar(printnumber[tot--]+'0');
	putchar(y);
	return ;
}
ll n,num[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=in();
	ll ans=0,l=1,r=n;
	for(int i=1;i<=n;i++)num[i]=in(),c[i]=inc();
	while(l<r)
	{
		ll tmp=min(num[l],num[r]);
		if(c[l]!=c[r])ans+=tmp;
		num[l]-=tmp;
		num[r]-=tmp;
		if(num[r]==0)r--;
		if(num[l]==0)l++;
	}
	out(ans,'\0');
	return 0;
}
//zdx bless me junior group AK
//lmr bless me junior group AK
//hzy bless me junior group AK
