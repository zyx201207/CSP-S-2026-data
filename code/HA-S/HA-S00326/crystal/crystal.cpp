#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back

inline int read()
{
	int x;
	cin>>x;
	return x;
}

int n,m;
int a[500010];
int sum[2000010],len[2000010],lz[2000010];

inline void build(int i,int l,int r)
{
	len[i]=r-l+1;
	if(l==r)
		return ;
	int mid=l+r>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	sum[i]=sum[i<<1]+sum[i<<1|1];
}

inline void push_down(int i)
{
	if(lz[i])
	{
		sum[i<<1]+=len[i<<1]*lz[i];
		sum[i<<1|1]+=len[i<<1|1]*lz[i];
		lz[i<<1]+=lz[i],lz[i<<1|1]+=lz[i];
		lz[i]=0;
	}
}

inline void add(int i,int l,int r,int xl,int xr,int k)
{
	if(xl>xr)
		return ;
	if(xl<=l&&r<=xr)
	{
		sum[i]+=k*len[i];
		lz[i]+=k;
		return ;
	}
	int mid=l+r>>1;
	push_down(i);
	if(xl<=mid)
		add(i<<1,l,mid,xl,xr,k);
	if(xr>mid)
		add(i<<1|1,mid+1,r,xl,xr,k);
	sum[i]=sum[i<<1]+sum[i<<1|1];
}

inline int ask(int i,int l,int r,int xl,int xr)
{
	if(xl<=l&&r<=xr)
		return sum[i];
	int res=0,mid=l+r>>1;
	push_down(i);
	if(xl<=mid)
		res+=ask(i<<1,l,mid,xl,xr);
	if(xr>mid)
		res+=ask(i<<1|1,mid+1,r,xl,xr);
	return res;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);int ans=0;
	build(1,1,n);
	for(int l=0,r=1;r<=n;r++)
	{
		add(1,1,n,1,r-1,a[r]-a[r-1]);
		while(l<r&&ask(1,1,n,l+1,r)>m)
			l++;
		ans=max(ans,r-l);
	}
	cout<<ans;
	return 0;
}

