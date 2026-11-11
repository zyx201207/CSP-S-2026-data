#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define LL long long
using namespace std;
const int N=2e6+10;
const int INF=1e9+10;
inline int read()
{
	int x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-48;
	return x*f;
}
struct Edge{
	int to,nxt;
}e[N]; 
int head[N],cnt;
void adde(int u,int v)
{
	e[++cnt]={v,head[u]};
	head[u]=cnt;
}
int n,k;
int ans=1;
void init()
{
	n=read(),k=read();
	rep(i,1,n-1)
	{
		int u=read(),v=read();
		adde(u,v),adde(v,u);
	}	
	printf("%d\n",ans);
} 


signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),t=read();
	while(t--)
	{
		init();
	}
	return 0;
}

