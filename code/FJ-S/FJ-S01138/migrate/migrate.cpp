#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=2e6+5;
struct node{
	ll l,r,s;
}a[N];
struct node1{
	ll s,t,k;
	bool operator < (const node1&x) const {
		return t>x.t;
	}
};
ll n,d;
bool al[N];
ll f(ll s,ll t,ll x){
	ll mid,res=s;
	while(s<t){
		mid=(s+t)>>1;
		if(a[mid].s>x)t=mid-1;
		else res=mid,s=mid+1;
	}
	return res;
}
void init(){
	memset(al,0,sizeof(al));
	for(ll i=1;i<=n;i++){
		if(!a[i].l)a[i].l=1;
		a[i].r=f(i,n,a[i].s+d);
		if(!al[a[i].r])
			al[a[i].r]=1,a[a[i].r].l=i;
	}
}
ll sum[4*N],laz[4*N];
void pushup(ll p){sum[p]=sum[p*2]+sum[p*2+1];}
void addtag(ll s,ll t,ll p,ll k){
	sum[p]+=k*(t-s+1);
	laz[p]+=k;
}
void pushdown(ll s,ll t,ll mid,ll p){
	if(laz[p]){
		addtag(s,mid,p*2,laz[p]);
		addtag(mid+1,t,p*2+1,laz[p]);
		laz[p]=0;
	}
}
void build(ll s,ll t,ll p){
	laz[p]=0;
	if(s==t){
		sum[p]=0;
		return ;
	}
	ll mid=(s+t)>>1;
	build(s,mid,p*2);
	build(mid+1,t,p*2+1);
	pushup(p);
}
ll query(ll s,ll t,ll ql,ll qr,ll p){
	if(ql<=s&&t<=qr)return sum[p];
	ll mid=(s+t)>>1,ans=0;
	pushdown(s,t,mid,p);
	if(ql<=mid)ans=query(s,mid,ql,qr,p*2);
	if(mid<qr)ans+=query(mid+1,t,ql,qr,p*2+1);
	pushup(p);
	return ans;
}
void update(ll s,ll t,ll ql,ll qr,ll p,ll k){
	if(ql<=s&&t<=qr)return addtag(s,t,p,k);
	ll mid=(s+t)>>1;
	pushdown(s,t,mid,p);
	if(mid>=ql)update(s,mid,ql,qr,p*2,k);
	if(mid<qr)update(mid+1,t,ql,qr,p*2+1,k);
	pushup(p);
} 
void solve(){
	cin>>n>>d;
	for(ll i=1;i<=n;i++)cin>>a[i].s;
	init();
	build(1,n,1);
	ll ans=0;
	priority_queue<node1>h;
	node1 u;
	for(ll i=1,s=0;i<=n;i++){
		while(!h.empty()&&h.top().t<i){
			u=h.top();h.pop();
			update(1,n,u.s,u.t,1,u.k);
		}
		if(i-1>=a[i].l)s=query(1,n,a[i].l,i-1,1)+1;
		ans+=s-1;
		u.s=i,u.t=a[i].r,u.k=s;
		h.push(u);
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll T;
	cin>>T>>T;
	while(T--)solve();
	return 0;
} 
