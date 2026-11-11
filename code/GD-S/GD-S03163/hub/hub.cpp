#include<bits/stdc++.h>
#define Code using
#define by namespace
#define wjb std
Code by wjb;
int in()
{
	int k=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
	return k*f;
}
void out(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else out(x/10),putchar(x%10+'0');
}
const int N=2e6+10;
vector<int>e[N];
int u[N],v[N];
struct dsu
{
	int f[N];
	void init(int n){for(int i=1;i<=n;i++)f[i]=i;}
	int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
	void merge(int u,int v){if((u=find(u))!=(v=find(v)))f[u]=v;}
}f;
int d[N];
queue<int>q;
int bfs(int S,int n)
{
	for(int i=1;i<=n;i++)d[i]=1e9;
	for(int i=1;i<=n;i++)if((S>>(i-1))&1)q.push(i),d[i]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v:e[u])if(d[v]>d[u]+1)d[v]=d[u]+1,q.push(v);
	}
	return *max_element(d+1,d+n+1);
}
void work()
{
	int n=in(),k=in(),ans=1e9;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<n;i++)
	{
		u[i]=in(),v[i]=in();
		e[u[i]].push_back(v[i]),e[v[i]].push_back(u[i]);
	}
	for(int S=0;S<(1<<n);S++)
	{
		if(__builtin_popcount(S)!=k)continue;
		f.init(n);
		for(int i=1;i<n;i++)
		{
			int x=u[i],y=v[i];
			if(((S>>(x-1))&1)&&((S>>(y-1))&1))f.merge(x,y);
		}
		unordered_set<int>s;
		for(int i=1;i<=n;i++)if((S>>(i-1))&1)s.insert(f.find(i));
		if(s.size()>2)continue;
		ans=min(ans,bfs(S,n));
	}
	out(ans),putchar('\n');
}
int dep[N],fa[N],dfn[N],siz[N],cnt=0;
void dfs(int u,int f)
{
	dfn[u]=++cnt,siz[u]=1;
	dep[u]=dep[f]+1,fa[u]=f;
	for(int v:e[u])if(v!=f)dfs(v,u),siz[u]+=siz[v];
}
bool check(int x,int n)
{
	int S=0;
	vector<pair<int,int>>s;
	for(int i=1;i<=n;i++)s.push_back({dep[i],i});
	sort(s.begin(),s.end());
	int a=0,b=0;
	for(int ss=s.size()-1;!b;ss--)
	{
		int bst=s[ss].second;
		if(a&&dfn[bst]>dfn[a]&&dfn[a]+siz[bst]-1<=dfn[bst])continue;
		if(b&&dfn[bst]>dfn[b]&&dfn[b]+siz[bst]-1<=dfn[bst])continue;
		int p=bst;
		for(int s=1;;s++,p=fa[p])
			if(!fa[p]||s==x+1){S|=(1<<(p-1));break;}
		if(!a)a=p;
		else b=p;
	}
	return bfs(S,n)<=x;
}
void work2()
{
	int n=in(),k=in();cnt=0;
	for(int i=1;i<=n;i++)e[i].clear(),dfn[i]=siz[i]=fa[i]=dep[i]=0;
	for(int i=1;i<n;i++)
	{
		u[i]=in(),v[i]=in();
		e[u[i]].push_back(v[i]),e[v[i]].push_back(u[i]);
	}
	dfs(1,0);
	int l=0,r=n,ans=1e9;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid,n))r=mid-1,ans=mid;
		else l=mid+1;
	}
	out(ans),putchar('\n');
}
int main()
{
//	system("fc hub4.ans hub.out");return 0;
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	int c=in();
	if(c==7||c==11||c==12)for(int t=in();t--;work2());
	else for(int t=in();t--;work());
	return 0;
}
