#include<iostream>
#include<cstdio> 
#include<vector> 
#include<cstring>
#define int long long 
using namespace std;
char buf[1<<20],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
int readint()
{
	int k=0,f=1,c=gc();
	for(;!isdigit(c);c=gc())
		if(c=='-') f=-1;
	for(;isdigit(c);c=gc())
		k=(k<<3)+(k<<1)+(c^48);
	return k*f;
}
const int N=1e3+10;
int n,m,ans=1e9; 
vector<int> e[N];
bool v[N];
bool qwq[N]; //是否建造了
int fa[N];
int dytree(int p,int fa)
{
	if(qwq[p])
		return 0;
	int res=1e9;
	for(int t:e[p])
	{
		if(t==fa) continue;
		res=min(res,dytree(t,p)+1);
	}
	return res;
} 
int find(int x)
{
	if(x!=fa[x])
		fa[x]=find(fa[x]);
	return fa[x];
}
void dtr(int p,int faa)
{
	for(int t:e[p])
	{
		if(t==faa) continue;
		if(qwq[t]&&qwq[p])
		{
			int fx=find(t),fy=find(p);
			if(fx!=fy)
			 	fa[fx]=fy;
		}
		dtr(t,p);
	}
}
int chk()
{
	int res=0;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	dtr(1,0);
	int s=0;
	for(int i=1;i<=n;i++)
		if(qwq[i]&&fa[i]==i)
			s++;
	if(s>2)
		return 1e9;
	for(int i=1;i<=n;i++)
	{
		if(qwq[i]) continue;
		res=max(res,dytree(i,0));
	}
	return res;
}
void dfs(int s,int p,string str)
{
	if(s==m)
	{
		memset(qwq,0,sizeof(qwq));
		int len=str.size();
		for(int i=0;i<len;i++)
			qwq[str[i]-'0']=1;
		ans=min(ans,chk());
//		cout<<str<<' '<<chk()<<'\n';
		return;
	}
	if(p==n+1) return;
	dfs(s+1,p+1,str+char(p+'0'));
	dfs(s,p+1,str);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int qwq=readint(),task=readint();
	while(task--)
	{
		ans=1e9;
		n=readint(),m=readint();
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=1;i<n;i++)
		{
			int u=readint(),v=readint();
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(0,1,"");
		printf("%lld\n",ans);
	}
}
