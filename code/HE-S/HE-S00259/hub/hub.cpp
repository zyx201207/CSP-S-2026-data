#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int read()
{
	char c=getchar();int f=1,x=0;
	while(c<'0' || c>'9') {(c=='-')?(f=-1):0;c=getchar();}
	while(c>='0' && c<='9') {x=x*10+(c-'0');c=getchar();}
	return x*f;
}

const int inf=0x3f3f3f3f3f3f3f3f;
const int N=1e6+5;
vector<int> e[N];
int _C_,T,n,k;
int fa[N];

int Find(int x) {return (x==fa[x])?x:(fa[x]=Find(fa[x]));}
void merge(int x,int y)
{
	x=Find(x),y=Find(y);
	if(x==y) return ;
	fa[x]=y;
}

bool check(int x)
{
	int l1=1,mid1=x,r1=x*2-1;
	if(r1>=n/2) return 1<=k;
	int r2=n/2,mid2=n/2-(x-1),l2=mid2-(x-1);
	if(l2<=r1) return 2<=k;
	return n/2-2*(x-1)-2*(x-1)<=k;
}

int maxn=0;
void dfs(int x,int f,int d,int i)
{
	maxn=max(maxn,d);
	for(auto to:e[x])
	{
		if(to==f || (i&(1ll<<(to-1)))) continue;
		dfs(to,x,d+1,i);
	}
}

void ___()
{
	int nn=(1ll<<n)-1,ans=inf;
	for(int i=0;i<nn;i++)
	{
		if(__builtin_popcount(i)!=k) continue;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int j=1;j<=n;j++)
		{
			if((i&(1ll<<(j-1)))==0) continue;
			for(auto to:e[j])
				if(i&(1ll<<(to-1)))
				{
					merge(j,to);
				}
		}
		int n1=0,n2=0;bool flag=1;
		for(int j=1;j<=n;j++)
		{
			if((i&(1ll<<(j-1)))==0) continue;
			if(!n1 && !n2) n1=Find(j);
			else if(n1 && n1!=Find(j) && !n2) n2=Find(j);
			else if(n1 && n2 && n2!=Find(j) && n1!=Find(j))
			{flag=0;break;}
		}
//		cout<<i<<'\n';
//		for(int j=1;j<=n;j++) cout<<Find(j)<<' ';cout<<'\n';
		if(!flag) continue;
		int res=0;
		for(int j=1;j<=n;j++)
		{
			if(i&(1ll<<(j-1))) continue;
			maxn=0;
			dfs(j,0,1,i);
			res=max(res,maxn);
		}
		ans=min(ans,res);
//		cout<<res<<'\n';
	}
	cout<<ans<<'\n';
}

signed main()
{
	fastio;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	_C_=read(),T=read();
	while(T--)
	{
		n=read(),k=read();
		for(int i=0;i<=n;i++) e[i].clear();
		for(int i=1,x,y;i<n;i++) x=read(),y=read(),e[x].push_back(y),e[y].push_back(x);
		if(k==n) {cout<<"0\n";continue;}
		if(n<=10) {___();continue;}
		int l=1,r=n,mid=0,ans=0;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(mid)) ans=mid,r=mid-1;
			else l=mid+1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
11 3
1 2
2 3
3 4
4 5
5 6
1 7
2 8
3 9
4 10
5 11

0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
