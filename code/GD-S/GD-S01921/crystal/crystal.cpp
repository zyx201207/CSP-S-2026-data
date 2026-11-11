#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n,m,a[500001],ans;
struct Segment_Tree
{
	struct Node
	{
		int l,r,sum,tag;
	}t[2000001];
	static inline int ls(int u) { return u<<1; }
	static inline int rs(int u) { return u<<1|1; }
	void work(int u,int k) { t[u].sum+=(t[u].r-t[u].l+1)*k,t[u].tag+=k; }
	void pushup(int u) { t[u].sum=t[ls(u)].sum+t[rs(u)].sum; }
	void pushdown(int u) { if(t[u].tag) work(ls(u),t[u].tag),work(rs(u),t[u].tag),t[u].tag=0; }
	void build(int u,int l,int r)
	{
		if((t[u].l=l)==(t[u].r=r)) return;
		build(ls(u),l,l+r>>1),build(rs(u),(l+r>>1)+1,r),pushup(u);
	}
	void update(int u,int l,int r,int k)
	{
		if(t[u].l>r||t[u].r<l) return;
		if(l<=t[u].l&&t[u].r<=r) return work(u,k);
		pushdown(u),update(ls(u),l,r,k),update(rs(u),l,r,k),pushup(u);
	}
	int query(int u,int l,int r)
	{
		if(t[u].l>r||t[u].r<l) return 0;
		if(l<=t[u].l&&t[u].r<=r) return t[u].sum;
		return pushdown(u),query(ls(u),l,r)+query(rs(u),l,r);
	}
}t;
int find(int l,int r,int k)
{
	int mid;
	while(l<r)
	{
		if(t.query(1,mid=l+r>>1,k)<=m) r=mid;
		else l=mid+1;
	}
	return l;
}
signed main()
{
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m,t.build(1,1,n);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) t.update(1,1,i-1,a[i]-a[i-1]),ans=max(ans,i-find(1,i,i)+1);
	cout<<ans;
}
