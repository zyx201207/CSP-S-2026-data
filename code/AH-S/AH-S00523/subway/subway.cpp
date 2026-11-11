#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+10,N=500;
vector<pair<int,int>> g[M+N];
int c,n,m,d,q,len[N],k,a,t,u,v,dis[M+500];
bool f[M+500];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qq;
int read()
{
	int s=0,flag=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')flag=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*flag;
}
void write(long long x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
	}
	else
	{
		if(x>9)write(x/10);
		putchar(x%10+'0');
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)len[i]=read();
	for(int i=1;i<=n;i++)
	{
		k=read();
		for(int j=1;j<=k;j++)
		{
			a=read();t=read();
			g[m+i].push_back({t,a});
			g[a].push_back({t,m+i});
		}
	}
	for(int i=1;i<=q;i++)
	{
		u=read();v=read();
		while(!qq.empty())qq.pop();
		memset(f,0,sizeof(f));
		memset(dis,0x3f,sizeof(dis));
		dis[u]=0;
		qq.push({0,u});
		for(int i=1;i<=m+n;i++)
		{
			auto r=qq.top();
			qq.pop();
			f[r.second]=1;
			dis[r.second]=r.first;
			for(auto w:g[r.second])qq.push({w.first+r.first,w.second});
			while(!qq.empty()&&f[qq.top().second])qq.pop();
			
		
		}write(dis[v]+len[u]+len[v]);puts("");
	}
	return 0;
}
