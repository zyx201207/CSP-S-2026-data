#include <bits/stdc++.h>
using namespace std;
long long n=1,m,a[500010],sum[500010];
struct tree{
	long long l,r,maxv,p;
}t[2000010];
void build(long long p,long long l,long long r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].maxv=a[l];return;
	}
	long long mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	t[p].maxv=max(t[p*2].maxv,t[p*2+1].maxv);
}
long long ask(long long p,long long l,long long r){
	if(t[p].l>=l&&t[p].r<=r) return t[p].maxv;
	long long mid=(t[p].l+t[p].r)/2,val=0;
	if(l<=mid) val=max(val,ask(p*2,l,r));
	if(r>mid) val=max(val,ask(p*2+1,l,r));
	return val;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	build(1,1,n);
	long long l=1,r=n;
	while(l<r){
		long long mid=(l+r+1)/2,flag=0;
		for(int i=mid;i<=n&&!flag;++i){
			long long f=ask(1,i-mid+1,i);
			long long x=f*mid-sum[i]+sum[i-mid];
			if(x<=m) flag=1;
		}
		if(flag) l=mid;
		else r=mid-1;
	}cout<<l;
	return 0;
}
