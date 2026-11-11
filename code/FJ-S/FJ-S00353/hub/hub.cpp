#include<iostream>
#include<vector>
#include<queue>
using namespace std;
inline int read(){char cc=getchar();int z=0,fh=1;while((cc<'0' || cc>'9') && cc!='-'){cc=getchar();}if(cc=='-'){fh=-1;cc=getchar();}while(cc>='0' && cc<='9'){z=z*10+cc-'0';cc=getchar();}return z*fh;}
inline void write(int x){if(x==0){putchar('0');return ;}if(x<0){x=-x;putchar('-');}int z[20],tt=0;while(x){z[++tt]=x%10;x/=10;}for(int i=tt;i;i--){putchar('0'+z[i]);}}
const int N=1e6+5;
int c;
int n,k;
vector<int> v[N];
bool flag[N];
int tot;
int a[N];
int ans;
bool yd[N];
queue<int> q;
int jl[N];
inline void ss(int d)
{
	flag[d]=true;
	for(auto to:v[d])
	{
		if(!yd[to] || flag[to]) continue;
		ss(to);
	}
}
inline bool check()
{
	for(int i=1;i<=n;i++)
	{
		flag[i]=false;
	}
	tot=0;
	for(int i=1;i<=k;i++)
	{
		int d=a[i];
		if(flag[d]) continue;
		ss(d);
		++tot;
	}
	return tot<=2;
}
inline int qmn()
{
	for(int i=1;i<=n;i++)
	{
		jl[i]=1e9;
	}
	for(int i=1;i<=k;i++)
	{
		q.push(a[i]);
		jl[a[i]]=0;
	}
	int ans=0;
	while(!q.empty())
	{
		int d=q.front();
		q.pop();
		ans=jl[d];
		for(auto t:v[d])
		{
			if(jl[t]!=1e9) continue;
			jl[t]=jl[d]+1;
			q.push(t);
		}
	}
	return ans;
}
inline void dfs(int d)
{
	if(d==k+1)
	{
		if(check())
		{
			ans=min(ans,qmn());
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(yd[i]) continue;
		yd[i]=true;
		a[d]=i;
		dfs(d+1);
		a[d]=0;
		yd[i]=false;
	}
}
int jla[N],jlb[N];
inline int bfs(int s,int jl[])
{
	for(int i=1;i<=n;i++)
	{
		jl[i]=-1;
	}
	jl[s]=0;
	q.push(s);
	int zy=s;
	while(!q.empty())
	{
		int d=q.front();
		q.pop();
		zy=d;
		for(auto t:v[d])
		{
			if(jl[t]!=-1) continue;
			jl[t]=jl[d]+1;
			q.push(t);
		}
	}
	return zy;
}
inline void init()
{
	n=read(),k=read();
	for(int i=1;i<=n;i++)
	{
		v[i].clear();
	}
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		v[x].push_back(y);
		v[y].push_back(x);
	}
//	if(k==2)
//	{
//		int a=bfs(1,jla);
//		int b=bfs(a,jla);
//		bfs(b,jlb);
//		int ans=0;
//		for(int i=1;i<=n;i++)
//		{
//			ans=max(ans,min(jla[i],jlb[i]));
//		}
//		write(ans);
//		putchar('\n');
//		return ;
//	}
	ans=1e9;
	dfs(1);
	write(ans);
	putchar('\n');
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();
	int t=read();
	while(t--)
	{
		init();
	}
	
	return 0;
}
