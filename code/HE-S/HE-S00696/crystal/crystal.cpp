#include<bits/stdc++.h>
using namespace std;
const int N=5e5+37;
long long x[N];
long long atr[N<<2],mtr[N<<2];
int ls(int p) {
	return p<<1;
}
int rs(int p) {
	return p<<1|1;
}
void up(int p) {
	atr[p]=atr[ls(p)]+atr[rs(p)];
	mtr[p]=max(mtr[ls(p)],mtr[rs(p)]);
}
void build(int p,int l,int r) {
	if(l==r) {
		atr[p]=mtr[p]=x[l];
	} else {
		int mid=(l+r)>>1;
		build(ls(p),l,mid);
		build(rs(p),mid+1,r);
		up(p);
	}
}
long long oda(int p,int l,int r,int ml,int mr) {
	if(ml<=l&&mr>=r) {
		return atr[p];
	} else {
		int mid=(l+r)>>1;
		long long ans=0;
		if(ml<=mid) {
			ans+=oda(ls(p),l,mid,ml,mr);
		}
		if(mr>mid) {
			ans+=oda(rs(p),mid+1,r,ml,mr);
		}
		return ans;
	}
}
long long odm(int p,int l,int r,int ml,int mr) {
	if(ml<=l&&mr>=r) {
		return mtr[p];
	} else {
		int mid=(l+r)>>1;
		long long ans=-4e18-37;
		if(ml<=mid) {
			ans=max(ans,odm(ls(p),l,mid,ml,mr));
		}
		if(mr>mid) {
			ans=max(ans,odm(rs(p),mid+1,r,ml,mr));
		}
		return ans;
	}
}
bool check(int mid,int a,long long b) {
	for(int i=1; i+mid-1<=a; i++) {
		long long h=oda(1,1,a,i,i+mid-1),zd=odm(1,1,a,i,i+mid-1);
		if(1ll*zd*(mid)<=b+h) {
			return true;
		}
	}
	return false;
}
signed main() {
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a,c=0,d;
	long long b;
	cin>>a>>b;
	for(int i=1; i<=a; i++) {
		cin>>x[i];
	}
	sort(x+1,x+1+a);
	build(1,1,a);
	int l=1,r=a;
	while(l<r) {
		int mid=(l+r+1)>>1;
		if(check(mid,a,b)) {
			l=mid;
//			cout<<1;
		} else {
			r=mid-1;
//			cout<<0;
		}
	}
	cout<<l;
	return 0;
}

