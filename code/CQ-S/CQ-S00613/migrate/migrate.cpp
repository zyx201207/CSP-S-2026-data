#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
const int L=21;
const int inf=1e9;
long long x[N];
bool vis[N];
int ed[N];
int nxt[N];
vector<int> g[N];
struct node
{
	int l,r;
	int mi,smi;
	int micnt;
	int smicnt;
	int add;
}tr[N<<2];
vector<pair<int,int> > a[N];
inline void pushup(int id)
{
	if(tr[id<<1].mi<tr[id<<1|1].mi)
	{
		tr[id].mi=tr[id<<1].mi;
		tr[id].micnt=tr[id<<1].micnt;
		if(tr[id<<1].smi<tr[id<<1|1].mi) 
		{
			tr[id].smi=tr[id<<1].smi,tr[id].smicnt=tr[id<<1].smicnt;
		}
		else if(tr[id<<1].smi>tr[id<<1|1].mi)
		{
			tr[id].smi=tr[id<<1|1].mi,tr[id].smicnt=tr[id<<1|1].micnt;
		}
		else
		{
			tr[id].smi=tr[id<<1].smi,tr[id].smicnt=tr[id<<1].smicnt+tr[id<<1|1].micnt;
		}
	}
	else if(tr[id<<1].mi>tr[id<<1|1].mi)
	{
		tr[id].mi=tr[id<<1|1].mi;
		tr[id].micnt=tr[id<<1|1].micnt;
		if(tr[id<<1].mi<tr[id<<1|1].smi) 
		{
			tr[id].smi=tr[id<<1].mi,tr[id].smicnt=tr[id<<1].micnt;
		}
		else if(tr[id<<1].mi>tr[id<<1|1].smi)
		{
			tr[id].smi=tr[id<<1|1].smi,tr[id].smicnt=tr[id<<1|1].smicnt;
		}
		else
		{
			tr[id].smi=tr[id<<1].mi,tr[id].smicnt=tr[id<<1].micnt+tr[id<<1|1].smicnt;
		}
	}
	else
	{
		tr[id].mi=tr[id<<1].mi;
		tr[id].micnt=tr[id<<1].micnt+tr[id<<1|1].micnt;
		if(tr[id<<1].smi<tr[id<<1|1].smi) 
		{
			tr[id].smi=tr[id<<1].smi,tr[id].smicnt=tr[id<<1].smicnt;
		}
		else if(tr[id<<1].smi>tr[id<<1|1].smi)
		{
			tr[id].smi=tr[id<<1|1].smi,tr[id].smicnt=tr[id<<1|1].smicnt;
		}
		else
		{
			tr[id].smi=tr[id<<1].smi,tr[id].smicnt=tr[id<<1].smicnt+tr[id<<1|1].smicnt;
		}
	}
}
inline void push(int id,int x)
{
	tr[id].mi+=x;
	tr[id].smi+=x;
	tr[id].add+=x;
}
inline void pushdown(int id)
{
	if(tr[id].add)
	{
		push(id<<1,tr[id].add);
		push(id<<1|1,tr[id].add);
		tr[id].add=0;
	}
}
void build(int id,int l,int r)
{
	tr[id].l=l,tr[id].r=r;
	tr[id].mi=0,tr[id].smi=inf;
	tr[id].micnt=tr[id].smicnt=0;
	tr[id].add=0;
	if(l==r)
	{
		tr[id].micnt=1;
		return;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	pushup(id);
}
void change(int id,int l,int r,int x)
{
	if(l<=tr[id].l&&tr[id].r<=r)
	{
		push(id,x);
		return;
	}
	pushdown(id);
	int mid=(tr[id].l+tr[id].r)>>1;
	if(l<=mid) change(id<<1,l,r,x);
	if(r>mid) change(id<<1|1,l,r,x);
	pushup(id);
}
long long ans;
void dfs(int u)
{
	vis[u]=1;
//	cout<<u<<"\n";
	for(auto v:a[u])
	{
		change(1,v.first,v.second,1);
	}
	int x=tr[1].mi,y=tr[1].smi;
//	if(u==1) cout<<x<<" "<<y<<"sdf\n";
	if(x==1) ans=ans+tr[1].micnt;
	else if(y==1) ans=ans+tr[1].smicnt;
	if(x>1) 
	{
		for(auto v:a[u])
		{
			change(1,v.first,v.second,-1);
		}
		return;
	}
	for(auto v:g[u])
	{
		dfs(v);
	}
	for(auto v:a[u])
	{
		change(1,v.first,v.second,-1);
	}
}
void flag(int u)
{
	vis[u]=1;
	for(auto v:g[u])
	{
		flag(v); 
	}
}
inline void read(int &ret)
{
	ret=0;
	char ch=getchar();
	int flag=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') 
	{
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	ret=ret*flag;
}
inline void read(long long &ret)
{
	ret=0;
	char ch=getchar();
	int flag=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') 
	{
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	ret=ret*flag;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cc,cas;
	read(cc),read(cas);
	while(cas--)
	{
		int n;
		long long d;
		read(n),read(d);
		for(int i=1;i<=n;i++) read(x[i]);
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
			a[i].clear();
			nxt[i]=ed[i]=0;
			vis[i]=0;
		}
		int now=1;
		for(int i=1;i<=n;i++)
		{
			while(now<n&&x[now+1]-x[i]<=d) now++;
			nxt[i]=now;
		}
		nxt[n+1]=n;
		int ll=n;
		for(int i=n;i>=1;i--)
		{
			if(nxt[i]==i) ll=i;
			ed[i]=ll;
		}
		int idcnt=0;
		for(int i=1;i<=n;i++)
		{
			if(nxt[i]!=i) g[nxt[i]].push_back(i);
		}
//		for(int i=1;i<=n;i++) 
//		{
//			printf("%d ",nxt[i]);
//		}
//		puts("");
		for(int i=1;i<=n;i++)
		{
			int x=nxt[i];
			int y=nxt[i]-1;
			int lst=x;
			while(nxt[x]!=x)
			{
				x=nxt[x];
				y=nxt[y];
//				cout<<x<<" "<<y<<"\n";
				if(x==y)
				{
					if(lst+1<=ed[i]) a[i].push_back({lst+1,ed[i]});
					break;
				}
				if(lst+1<=y) a[i].push_back({lst+1,y});
				else break;
				lst=x; 
			}
			if(nxt[i]>i+1)
			{
				x=nxt[i];
				y=nxt[i]-2;
				lst=x;
				while(nxt[x]!=x)
				{
					x=nxt[x];
					y=nxt[y];
//					cout<<x<<" "<<y<<"\n";
					if(x==y)
					{
						if(lst+1<=ed[i]) a[i].push_back({lst+1,ed[i]});
						break;
					}
					if(lst+1<=y) a[i].push_back({lst+1,y});
					else break;
					lst=x; 
				}
			} 
			
		}
//		for(int i=1;i<=n;i++)
//		{
//			printf("%d:\n",i);
//			for(auto j:a[i]) printf("%d %d\n",j.first,j.second);
//			puts("");
//		}
//		cout<<"ok???\n";
		build(1,1,n);
		ans=0;
//		cout<<"OK???\n";
		for(int i=n;i>=1;i--)
		{
			if(!vis[i])
			{
				dfs(i);
				flag(i);
			}
		}
//		dfs(n);
		printf("%lld\n",ans);
	}
}
