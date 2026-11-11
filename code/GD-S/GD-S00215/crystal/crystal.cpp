#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
namespace sgt{
int ans[N<<2],tag[N<<2];
int lc(int p){ return p<<1; }
int rc(int p){ return (p<<1)|1; }
void f(int p,int nl,int nr,int v){
	ans[p]+=(nr-nl+1)*v;
	tag[p]+=v;
}
void pushUp(int p){ ans[p]=ans[lc(p)]+ans[rc(p)]; }
void pushDown(int p,int nl,int nr){
	int mid=(nl+nr)>>1;
	f(lc(p),nl,mid,tag[p]);
	f(rc(p),mid+1,nr,tag[p]);
	tag[p]=0;
}
void update(int p,int nl,int nr,int l,int r,int v){
	if(l<=nl&&nr<=r){
		f(p,nl,nr,v);
		return;
	}
	pushDown(p,nl,nr);
	int mid=(nl+nr)>>1;
	if(l<=mid) update(lc(p),nl,mid,l,r,v);
	if(mid+1<=r) update(rc(p),mid+1,nr,l,r,v);
	pushUp(p);
}
int query(int p,int nl,int nr,int l,int r){
	if(l<=nl&&nr<=r) return ans[p];
	pushDown(p,nl,nr);
	int res=0,mid=(nl+nr)>>1;
	if(l<=mid) res+=query(lc(p),nl,mid,l,r);
	if(mid+1<=r) res+=query(rc(p),mid+1,nr,l,r);
	return res;
}
};
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	int ans=1;
	for(int i=2;i<=n;++i){
		sgt::update(1,1,n,1,i-1,a[i]-a[i-1]);
		int x=sgt::query(1,1,n,1,i-1);
		if(x<=m){
			ans=i;
			continue;
		}
		int l=1,r=i;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(sgt::query(1,1,n,mid,i)<=m) r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans<<endl;
	return 0;
}//[45,100]

