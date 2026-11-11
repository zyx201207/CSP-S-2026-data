//Author: mairuisheng
//#pragma GCC optimize(3)
#include<cstdio>
#include<vector>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char s;
	s=getchar();
	while(s<48||s>57)
	{
		if(s=='-')f=-f;
		s=getchar();
	}
	while(s>47&&s<58)
	{
		x=(x<<3)+(x<<1)+s-48;
		s=getchar();
	}
	return x*f;
}
constexpr int N=1e6+1;
int C;
int n,m;
vector<int> g[N];
int dep[N],f[N];
int cnt;
void SubA()
{
	if(m>=(n>>1))
	{
		puts("1");
		return;
	}
	else puts("3");
}
bool dfs(int u,int fa,int w)
{
	dep[u]=f[u]=dep[fa]+1;
	for(int v:g[u])
	{
		if(v==fa)continue;
		if(!dfs(v,u,w))return false;
		f[u]=max(f[u],f[v]);
	}
	if(f[u]-dep[u]>=w)
	{
		f[u]=dep[u];
		++cnt;
		if(cnt>2)return false;
	}
	return true;
}
void Solve()
{
	n=read();
	m=read();
	int i,u,v;
	for(i=1;i<=n;++i)g[i].clear();
	for(i=1;i<n;++i)
	{
		u=read();
		v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(n==m)
	{
		puts("0");
		return;
	}
	else if(m==n-1)
	{
		puts("1");
		return;
	}
	else
	{
		int l=1,r=n,mid;
		while(l<r)
		{
			mid=l+r>>1;
			cnt=0;
			if(dfs(1,0,mid))r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
		return;
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	C=read();
	int T;
	T=read();
	while(T--)Solve();
	return 0;
}

