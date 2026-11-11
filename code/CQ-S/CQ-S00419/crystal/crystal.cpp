#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000005
#define il inline
int n,m;
int a[N];
struct tree{
	int l,r,ls,rs;
	int s,lz;
}tr[N<<1]; int rt,tot;
il void pu(int p){tr[p].s=tr[tr[p].ls].s+tr[tr[p].rs].s;}
il void pd(int p){
	if(!tr[p].lz)return;
	tr[tr[p].ls].lz+=tr[p].lz;
	tr[tr[p].rs].lz+=tr[p].lz;
	tr[tr[p].ls].s+=tr[p].lz*(tr[tr[p].ls].r-tr[tr[p].ls].l+1);
	tr[tr[p].rs].s+=tr[p].lz*(tr[tr[p].rs].r-tr[tr[p].rs].l+1);
	tr[p].lz=0;
}
void build(int &p,int l,int r){
	p=++tot; tr[p].l=l,tr[p].r=r;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(tr[p].ls,l,mid); build(tr[p].rs,mid+1,r);
	pu(p);
}
void upd(int p,int l,int r,int x){
	if(l>r)return;
	if(l<=tr[p].l&&tr[p].r<=r){
		tr[p].s+=x*(tr[p].r-tr[p].l+1);
		tr[p].lz+=x;
		return;
	}
	pd(p);
	int mid=(tr[p].l+tr[p].r)>>1;
	if(l<=mid)upd(tr[p].ls,l,r,x);
	if(r>mid)upd(tr[p].rs,l,r,x);
	pu(p);
}
int qry(int p,int x){
	if(!p)return -1;
	if(tr[p].l==tr[p].r)return tr[p].s>x?tr[p].l+1:tr[p].l;
	pd(p);
	if(tr[tr[p].rs].s<=x)return qry(tr[p].ls,x-tr[tr[p].rs].s);
	return qry(tr[p].rs,x);
}
int qsum(int p,int l,int r){
	if(l<=tr[p].l&&tr[p].r<=r)return tr[p].s;
	int mid=(tr[p].l+tr[p].r)>>1,s=0; pd(p);
	if(l<=mid)s=qsum(tr[p].ls,l,r);
	if(r>mid)s+=qsum(tr[p].rs,l,r);
	return s;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	build(rt,1,n);
	int mx=1;
	for(int i=2;i<=n;i++){
		int d=a[i]-a[i-1];
		upd(rt,1,i-1,d);
		int l=qry(rt,m);
		if(l==-1)continue;
//		if(qsum(rt,l,i)>m)cout<<i<<" "<<"fail!: "<<qsum(rt,l,i)<<'\n';
		mx=max(mx,i-l+1);
	}
	cout<<mx;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
