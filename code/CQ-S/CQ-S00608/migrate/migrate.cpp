#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define psb push_back
#define mid (l+r>>1)
#define endl '\n'

const int mx=2e6+5;
const ll inf=1e18;
int cs,t,n;
ll m,s,a[mx];
pii f[mx];

//struct {
//	#define ls (id<<1)
//	#define rs (ls|1)
//	struct st{
//		int l,r;
//		pii sc;
//	}tr[mx<<2];
//	pii get(pii x,pii y){
//		if(x.F==y.F) return {x.F,1};
//		return (x.F<y.F?x:y);
//	}
//	void psp(int id){
//		tr[id].sc=get(tr[ls].sc,tr[rs].sc);
//	}
//	void bld(int id,int l,int r){
//		tr[id]={l,r,{1e9,0}};
//		if(l==r) return ;
//		bld(ls,l,mid),bld(rs,mid+1,r);
//	}
//	void chg(int id,int l,pii x){
//		if(l<tr[id].l||tr[id].r<l) return ;
//		if(tr[id].l==tr[id].r){
//			tr[id].sc=x;
//			return ;
//		}
//		chg(ls,l,x),chg(rs,l,x);
//		psp(id);
//	}
//	pii qry(int id,int l,int r){
//		if(r<tr[id].l||tr[id].r<l) return {1e9,0};
//		if(l<=tr[id].l&&tr[id].r<=r) return tr[id].sc;
//		return get(qry(ls,l,r),qry(rs,l,r));
//	}
//}sgt;

void slv(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	s=0;
	if(cs<11||cs>14){
//		for(int i=1;i<=n;i++){
//			sgt.bld(1,i,n);
//			sgt.chg(1,i,{0,0});
//			for(int k=i,j=i+1;j<=n;j++){
//				while(a[j]-a[k]>m) k++;
//				if(j==k) break;
//				pii x=sgt.qry(1,k,j-1);
//				s+=x.S;
//				cout<<i<<" "<<k<<" "<<j<<" "<<x.F<<" "<<x.S<<endl;
//				if(x.S) cout<<j<<" "<<k<<" "<<i<<endl;
//				sgt.chg(1,j,{x.F+1,x.S});
//			}
//		}
		for(int i=1;i<=n;i++){
			f[i]={0,-1};
			for(int k=i,j=i+1;j<=n;j++){
				while(a[j]-a[k]>m) k++;
				if(k==j) break;
				f[j]={f[k].F+1,f[k].S};
				if(k+1<j&&f[k+1].F==f[k].F) f[j].S=(f[k+1].S>=0||(k+2<j&&f[k+2].F==f[k].F));
//				cout<<i<<" "<<k<<" "<<j<<" "<<f[k].F<<" "<<f[k+1].F<<" "<<f[k].S<<endl;
				s+=(!f[j].S);
			}
		}
		cout<<s<<endl;
		return ;
	}
	if(cs<13){
		ll dd=m/(a[2]-a[1]);
		if(dd<2){
			cout<<0<<endl;
			return ;
		}
		cout<<max((ll)n-2ll*dd+1ll,0ll)<<endl;
		return ;
	}
	if(cs<15){
		int ps=1;
		while(a[n]-a[ps]>m) ps++;
		int pr=ps+1;
		while(pr<=n&&a[pr]-a[ps-1]<=m) pr++;
		pr--;
		for(int i=1;i<ps;i++){
			if(a[ps+1]-a[i]<=m) break;
			if(a[ps-1]-a[i]<=m) s+=pr-ps;
		}
		for(int i=1;i<ps;i++){
			if(a[pr+1]-a[i]<=m) break;
			if(a[ps+1]-a[i]<=m) s+=n-pr;
		}
		cout<<s<<endl;
		return ;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cs>>t;
	while(t--) slv();
	return 0;
}
