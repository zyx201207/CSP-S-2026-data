#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char buf[(1<<20)],*p1=buf,*p2=buf;
inline char gc()
{
	if(p1==p2)
	{
		p2=(p1=buf)+fread(buf,1,(1<<20),stdin);
		if(p1==p2)return EOF;
	}
	return *p1++;
}
ll printnumber[105];
inline ll in()
{
	ll ans=0,f=1;
	char ch=gc();
	while(ch<'0'||ch>'9')f=(ch=='-'?-1:1),ch=gc();
	while(ch>='0'&&ch<='9')ans=ans*10+ch-48,ch=gc();
	return ans*f;
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
ll n,m,a[500005],ans[300005];
bool vis[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=in(),m=in();
	for(int i=1;i<=n;i++)a[i]=in();
	for(int i=1;i<=n;i++)
	{
		stack<ll> st;
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]])
			{
				while(st.top()!=a[j])vis[st.top()]=0,st.pop();
			}
			else st.push(a[j]),vis[a[j]]=1;
		}
		while(!st.empty())ans[st.top()]++,vis[st.top()]=0,st.pop();
	}
	for(int i=1;i<=m;i++)out(ans[i],' ');
	return 0;
}
//zdx bless me junior group AK
//lmr bless me junior group AK
//hzy bless me junior group AK

