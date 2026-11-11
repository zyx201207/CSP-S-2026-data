#include<bits/stdc++.h>
//#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> pir;
const int MAXN=5e5+5,mod=998244353,inf=0x3f3f3f3f;
int n;
ll m,a[MAXN];
struct SegTree{
	int l,r;
	ll v,tag;
}t[MAXN<<2];
inline void addtag(int x,ll w){
	t[x].v+=(t[x].r-t[x].l+1)*w;
	t[x].tag+=w;
}
inline void pushup(int x){
	t[x].v=t[x<<1].v+t[x<<1|1].v;
}
inline void pushdown(int x){
	if(!t[x].tag)
		return ;
	addtag(x<<1,t[x].tag);
	addtag(x<<1|1,t[x].tag);
	t[x].tag=0;
}
void bt(int x,int l,int r){
	t[x]={l,r,0,0};
	if(l==r)
		return ;
	int mid=(l+r)>>1;
	bt(x<<1,l,mid);
	bt(x<<1|1,mid+1,r);
}
void upd(int x,int l,int r,ll w){
	if(l>r)
		return ;
	if(l<=t[x].l&&t[x].r<=r)
		return addtag(x,w);
	pushdown(x);
	int mid=(t[x].l+t[x].r)>>1;
	if(l<=mid)
		upd(x<<1,l,r,w);
	if(mid<r)
		upd(x<<1|1,l,r,w);
	pushup(x);
}
inline int query(int x,ll w){
	if(t[x].v<=w)
		return 0;
	if(t[x].l==t[x].r)
		return t[x].l;
	pushdown(x);
	if(t[x<<1|1].v<=w)
		return query(x<<1,w-t[x<<1|1].v);
	return query(x<<1|1,w);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	bt(1,1,n);
	int ans=0;
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		upd(1,1,i-1,a[i]-a[i-1]);
		ans=max(ans,i-query(1,m));
	}
	cout<<ans;
	return 0;
}
