#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pir pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
inline int re()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
inline ll rell()
{
	ll x=0;int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
template<typename T> inline void chkmin(T &a,T b){a=min(a,b);}
template<typename T> inline void chkmax(T &a,T b){a=max(a,b);}
const int N=2000010,lim=4;
int C,T;
int n;ll d;
ll pos[N];
int fa[N],to[N],val[N][lim][lim];
void getval(int p)
{
	if(fa[p]==0||pos[fa[p]+1]-pos[fa[p]]>d)
	{
		for(int i=0;i<lim;i++) for(int j=0;j<lim;j++) val[p][i][j]=0;
		return;
	}
	int len1=0,len2=0;
	if(to[fa[fa[p]]+1]==fa[p]+1)
	{
		int l=fa[fa[p]]+1,r=fa[p],mid;
		while(l<r)
		{
			mid=(l+r+1)>>1;
			if(to[mid]==fa[p]+1) l=mid;
			else r=mid-1;
		}
		len1=l-fa[fa[p]];
	}
	if(fa[fa[p]]+1+len1<=fa[p])
	{
		if(to[fa[fa[p]]+1+len1]==fa[p]+2)
		{
			int l=fa[fa[p]]+1+len1,r=fa[p],mid;
			while(l<r)
			{
				mid=(l+r+1)>>1;
				if(to[mid]==fa[p]+2) l=mid;
				else r=mid-1;
			}
			len2=l-(fa[fa[p]]+1+len1)+1;
		}
	}
	int pos=to[fa[fa[p]]+1],pos2=to[fa[fa[p]]+2];
	for(int i=0;i<lim;i++) for(int j=0;j<lim;j++)
	{
		int res=0,v1,v2;
		if(i==2) res+=len1;
		if(i+j==2) res+=len2;
		if(pos==fa[p]+1) v1=i;else if(pos==fa[p]+2) v1=min(3,i+j);else v1=3;
		if(fa[fa[p]]+2>fa[p]) v2=0;else if(pos2==fa[p]+1) v2=i;else if(pos2==fa[p]+2) v2=min(3,i+j);else v2=3;
		val[p][i][j]=res+val[fa[p]][v1][v2];
	}
	return;
}
void work()
{
	n=re();d=rell();
	for(int i=1;i<=n;i++) pos[i]=rell();
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n,mid;
		while(l<r)
		{
			mid=(l+r+1)>>1;
			if(pos[mid]-pos[i]<=d) l=mid;
			else r=mid-1;
		}
		to[i]=l;
	}
	for(int i=1;i<n;i++)
	{
		if(pos[i+1]-pos[1]<=d) fa[i]=0;
		else
		{
			int l=1,r=i-1,mid;
			while(l<r)
			{
				mid=(l+r+1)>>1;
				if(pos[i+1]-pos[mid]<=d) r=mid-1;
				else l=mid;
			}
			fa[i]=l;
		}
		getval(i);
	}
	ll ans=0;
	for(int i=2;i<=n;i++)
	{
		if(pos[i]-pos[i-1]>d) continue;
		if(fa[i-1]==i-2) ans+=val[i-1][1][0];
		else ans+=val[i-1][1][1];
	}
	printf("%lld\n",ans);
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=re();T=re();
	while(T--) work();
	return 0;
}
