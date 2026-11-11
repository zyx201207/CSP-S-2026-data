#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100,M=505;
int C,T,n,m,c[N],e[N],b[N],f[N][20],z=0,s=0,D,q,d[N];
vector<int>a[N];
bool cp(int x,int y)
{
	return d[x]>d[y];
}
int lc(int x,int y)
{
	if(d[x]<d[y])
	{
		swap(x,y);
	}
	for(int i=19;i>=0;i--)
	{
		if(d[f[x][i]]>=d[y])
		{
			x=f[x][i];
		}
	}
	if(x==y)
	{
		return x;
	}
	for(int i=19;i>=0;i--)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int di(int x,int y)
{
	int v=lc(x,y);
	return d[x]+d[y]-2*d[v];
}
void p(int x,int fa)
{
	c[x]=++z;
	e[z]=x;
	d[x]=d[fa]+1;
	f[x][0]=fa;
	for(int i=1;i<20;i++)
	{
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(int v:a[x])
	{
		if(v!=fa)
		{
			p(v,x);
		}
	}
}
bool ch(int x)
{
	set<int>t;
	int z=0;
	for(int j=1,i;j<=n;j++)
	{
		i=b[j];
		int s=2*x+1;
		auto v=t.upper_bound(c[i]);
		if(v!=t.end())
		{
			s=min(s,di(e[(*v)],i));
		}
		if(v!=t.begin())
		{
			v--;
			s=min(s,di(e[(*v)],i));
		}
		//cout<<i<<' '<<s<<"\n";
		if(s>2*x)
		{
			z++;
			t.insert(c[i]);
		}
		if(z>m)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin>>C>>T;
	for(;T--;)
	{
		cin>>n>>m;
		for(int i=1,x,y;i<n;i++)
		{
			cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		z=0;
		p(1,0);
		for(int i=1;i<=n;i++)
		{
			b[i]=i;
		}
		sort(b+1,b+n+1,cp);
		int l=0,r=n-1;
		for(;l<r;)
		{
			int m=(l+r)/2;
			if(ch(m))
			{
				r=m;
			}
			else
			{
				l=m+1;
			}
		}
		cout<<l<<"\n";
		for(int i=1;i<=n;i++)
		{
			vector<int>().swap(a[i]);
		}
	}
}
