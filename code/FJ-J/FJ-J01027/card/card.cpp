#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ax[500010],ans[300010],fnd[300010],tr[2000010],lazy[2000010];
void build(int l,int r,int k)
{
	if(l==r)
	{
		tr[k]=1;
		lazy[k]=0;
		return;
	}
	lazy[k]=0;
	int mid=l+r>>1;
	build(l,mid,k*2);
	build(mid+1,r,k*2+1);
	tr[k]=tr[k*2]+tr[k*2+1];
	return;
}
void add(int l,int r,int k,int v)
{
	tr[k]+=(r-l+1)*v;
	lazy[k]+=v;
	return;
}
void pushback(int l,int r,int k)
{
	if(lazy[k]!=0)
	{
		int mid=l+r>>1;
		add(l,mid,k*2,lazy[k]);
		add(mid+1,r,k*2+1,lazy[k]);
		lazy[k]=0;
	}
	return;
}
void change(int l,int r,int k,int x,int y,int v)
{
	if(l>=x&&r<=y)
	{
		add(l,r,k,v);
		return;
	}
	pushback(l,r,k);
	int mid=l+r>>1;
	if(x<=mid) change(l,mid,k*2,x,y,v);
	if(y>mid) change(mid+1,r,k*2+1,x,y,v);
	tr[k]=tr[k*2]+tr[k*2+1];
	return;
}
int query(int l,int r,int k,int x)
{
	if(l==r) return tr[k];
	pushback(l,r,k);
	int ans=0,mid=l+r>>1;
	if(x<=mid) ans+=query(l,mid,k*2,x);
	if(x>mid) ans+=query(mid+1,r,k*2+1,x);
	return ans;
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;++i)
	  cin>>ax[i];
	for (int k=1;k<=n;++k)
	{
		build(1,n,1);
		for (int i=1;i<=m;++i)
		  fnd[i]=0;
		for (int i=k;i<=n;++i)
		{
			if(fnd[ax[i]]!=0&&query(1,n,1,fnd[ax[i]])!=0) change(1,n,1,fnd[ax[i]],i,-1);
			fnd[ax[i]]=i;
		}
		int cnt=0;
		for (int i=k;i<=n;++i)
		  if(query(1,n,1,i)==1) ++ans[ax[i]];
	}
	for (int i=1;i<=m;++i)
	  cout<<ans[i]<<' ';
	cout<<'\n';
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
