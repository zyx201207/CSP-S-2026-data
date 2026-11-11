#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||'9'<c){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
		x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
inline void write(ll x)
{
	if(x==0){
		putchar('0');
		return ;
	}
	if(x<0){
		putchar('-');
		x=-x;
	}
	int tot=0;
	char c[64];
	while(x>0){
		c[tot++]=x%10+'0';
		x/=10;
	}
	while(tot>0)
		putchar(c[--tot]);
}
ll n,m,M,e[500005],t=1,h=1,ans[100005],k=1,fans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),M=read();
	m=M;
	for(int i=1;i<=n;i++)
		e[i]=read();
	sort(e+1,e+1+n);
	ans[k]=1;
	while(m>0&&t<=n){
		if(e[t]!=e[t+1]&&t<n)
		{
			int x=e[t+1]-e[t];
			if(x*t<=m)
			{
				m=m-(t-h+1)*x;
				e[t]+=x;
				ans[k]++;
				t++;
			}
			else if(x>m){
				ans[++k]=1;
				m=M;
				t++;
				h=t;
				continue;
			}
			else break;
		}
		else if(t<n){
			t++,ans[k]++;
		}
		else t++;
	}
	while(e[t]==e[t+1]&&t<=n)
		t++,ans[k]++;
	for(int i=1;i<=k;i++)
		fans=max(fans,ans[i]);
	write(fans);
	putchar('\n');
	return 0;
}
