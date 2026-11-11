#include <bits/stdc++.h>
#define lc  (t<<1)
#define rc ((t<<1)|1)
using namespace std;
const int maxn=2e6+100;
const long long INF=0x3f3f3f3f3f3f3f3f;
long long cnt,qk;
int n,c,k,ql,qr;
long long a[maxn],ans[maxn],m,dp[maxn];
struct info{
	long long minv,minu;
	info operator + (const info & o)const{
		info c;
		if(minv==o.minv){
			c.minv=minv;
			c.minu=minu+o.minu;
		}
		else if(minv>o.minv){
			c.minv=o.minv;
			c.minu=o.minu;
		}
		else{
			c.minv=minv;
			c.minu=minu;
		}
		return c;
	}
};
info res;
struct node{
	int l,r;
	info s; 
}tree[maxn*4];
void up(int t){
	tree[t].s=tree[lc].s+tree[rc].s;
}
void build(int t,int l,int r){
	tree[t].l=l;
	tree[t].r=r;
	if(l==r){
		tree[t].s.minu=0;
		tree[t].s.minv=INF;
		return;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	up(t); 
} 
void add(int t){
	if(tree[t].l==tree[t].r){
		tree[t].s.minu=1;
		tree[t].s.minv=qk;
		return; 
	}
	int mid=(tree[t].l+tree[t].r)>>1;
	if(ql<=mid) add(lc);
	else add(rc);
	up(t);
}
void ask(int t){
	if(ql<=tree[t].l && tree[t].r<=qr){
		res=res+tree[t].s;
		return;
	}
	int mid=(tree[t].l+tree[t].r)>>1;
	if(ql<=mid) ask(lc);
	if(qr>mid) ask(rc);
}
void solve(int s){
	fill(dp+1,dp+1+n,INF);
	memset(ans,0,sizeof(ans));
	dp[s]=0;
	int p=s;
	build(1,1,n);
	ql=qr=s,qk=0;
	add(1);
	for(int i=s+1;i<=n;i++){
		while(p<=i && (a[i]-a[p])>m) p++;
		if(p==i) break;
		ql=p,qr=i-1;
		res.minu=0,res.minv=INF;
		ask(1);
		dp[i]=res.minv+1;
		if(res.minu==2) cnt++;
		ql=i,qk=dp[i];
		add(1);
	}
	//for(int i=1;i<=n;i++) cout << ans[i] << ' ';
	//cout << '\n';
	//for(int i=s;i<=n;i++) if(ans[i]==2) cnt++;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> k;
	while(k--){
		cnt=0;
		cin >> n >> m;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		for(int i=1;i<n;i++) solve(i);
		cout << cnt << '\n';
	}
	return 0;
} 
