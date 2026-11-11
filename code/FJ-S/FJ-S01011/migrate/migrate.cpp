#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define endl '\n'
using namespace std;
int read();
const int N=2e6+10,inf=1e18;
int c,t,n,d,x[N],sum,ans;
PII dp[N];
struct Seg{
	PII tree[N<<2];
	inline PII maxp(PII x,PII y) {
		if(x.first==y.first) return make_pair(x.first,x.second+y.second);
		return (x.first>y.first?y:x);
	}
	inline void pushup(int p) {
		tree[p]=maxp(tree[p<<1],tree[p<<1|1]);
	}
	inline void build(int p,int l,int r) {
		if(l==r) return tree[p]=make_pair(inf,0),void();
		int mid=(l+r)>>1;
		build(p<<1,l,mid),build(p<<1|1,mid+1,r);
		pushup(p);
	}
	inline void update(int p,int l,int r,int x,PII d) {
		if(l==r) return tree[p]=d,void();
		int mid=(l+r)>>1;
		if(x<=mid) update(p<<1,l,mid,x,d);
		else update(p<<1|1,mid+1,r,x,d);
		pushup(p);
	}
	inline PII query(int p,int l,int r,int ql,int qr) {
		if(ql<=l && r<=qr) return tree[p];
		int mid=(l+r)>>1;
		PII ans=make_pair(inf,0);
		if(ql<=mid) ans=maxp(ans,query(p<<1,l,mid,ql,qr));
		if(mid<qr) ans=maxp(ans,query(p<<1|1,mid+1,r,ql,qr));
		return ans;
	}
}T;
inline void solveA() {
	n=read(),d=read(),ans=sum=0;
	for(int i=1;i<=n;i++) x[i]=read();
	int op=d/(x[2]-x[1]);
	if(op<=1) return cout<<0<<endl,void();
	for(int i=1;i<=n;i++) dp[i]=make_pair(inf,0);
	T.build(1,1,n);
	dp[1]=make_pair(0,1),T.update(1,1,n,1,dp[1]);
	for(int i=2;i<=n;i++) {
		dp[i]=T.query(1,1,n,i-op,i-1),dp[i].first++;
		if(dp[i].second==2) sum++;
		T.update(1,1,n,i,dp[i]);
	}
	for(int i=n;i>=1;i--) {
		ans+=sum;
		if(dp[i].second==2) sum--;
	}
	cout<<ans<<endl;
}
inline void solve() {
	n=read(),d=read(),ans=0;
	for(int i=1;i<=n;i++) x[i]=read();
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) dp[j]=make_pair(inf,0);
		T.build(1,1,n);
		dp[i]=make_pair(0,1),T.update(1,1,n,i,dp[i]);
		for(int j=i+1;j<=n;j++) {
			int pos=lower_bound(x+i,x+j,x[j]-d)-x;
			if(pos>=j) break;
			dp[j]=T.query(1,1,n,pos,j-1),dp[j].first++;
			if(dp[j].second==2) ans++;
			T.update(1,1,n,j,dp[j]);
		}
	}
	cout<<ans<<endl;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	if(c==11 || c==12) while(t--) solveA();
	else while(t--) solve();
	return 0;
}
int read() {
	int Ca=0;char Cr=' ';int Cf=1;
	while(Cr<'0' || Cr>'9') {Cr=getchar();if(Cr=='-') Cf=-1;}
	while(Cr>='0' && Cr<='9') {Ca=(Ca<<3)+(Ca<<1)+Cr-48,Cr=getchar();}
	return Ca*Cf;
}

