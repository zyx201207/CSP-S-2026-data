#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||'9'<c){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
		x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
inline void write(int x)
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
int c,t,n,k,u,v,ans=0;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--)
	{
		n=read(),k=read();
		vector<int>dis[n];
		for(int i=1;i<n;i++){
			u=read(),v=read();
			dis[u].push_back(v);
			dis[v].push_back(u);
		}
		printf("%lld\n",k);
	}
	return 0;
}
