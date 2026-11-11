#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005,INF=1e9;
int n,nxt[N],lst[N],pos[N],cnt[N][N],mn[N][N];
ll x[N],d;
struct Seg {
	struct Node {int l,r,mn,lzy;}tree[N<<2];
	inline void pushup(int p) {tree[p].mn=min(tree[p*2].mn,tree[p*2+1].mn);}
	inline void build(int p,int l,int r) {
		tree[p].l=l,tree[p].r=r,tree[p].lzy=INF,tree[p].mn=INF;
		if (l==r) return ;
		int mid=(l+r)>>1;
		build(p*2,l,mid); build(p*2+1,mid+1,r);
		pushup(p);
	}
	inline void pushdown(int p) {
		tree[p*2].mn=min(tree[p*2].mn,tree[p].lzy),tree[p*2].lzy=min(tree[p*2].lzy,tree[p].lzy);
		tree[p*2+1].mn=min(tree[p*2+1].mn,tree[p].lzy),tree[p*2+1].lzy=min(tree[p*2+1].lzy,tree[p].lzy);
		tree[p].lzy=INF;
	}
	inline void modify(int p,int l,int r,int k) {
		if (l<=tree[p].l&&tree[p].r<=r) {tree[p].mn=min(tree[p].mn,k),tree[p].lzy=min(tree[p].lzy,k); return ;}
		int mid=(tree[p].l+tree[p].r)>>1,res=INF; pushdown(p);
		if (l<=mid) modify(p*2,l,r,k);
		if (r>mid) modify(p*2+1,l,r,k);
		pushup(p);
	}
	inline int query(int p,int l,int r) {
		if (l<=tree[p].l&&tree[p].r<=r) return tree[p].mn;
		int mid=(tree[p].l+tree[p].r)>>1,res=INF; pushdown(p);
		if (l<=mid) res=min(res,query(p*2,l,r));
		if (r>mid) res=min(res,query(p*2+1,l,r));
		return res;
	}
}T1;
struct Seg2 {
	struct Node {int l,r,sum;}tree[N<<2];
	inline void pushup(int p) {tree[p].sum=min(3,tree[p*2].sum+tree[p*2+1].sum);}
	inline void build(int p,int l,int r) {
		tree[p].l=l,tree[p].r=r,tree[p].sum=0;
		if (l==r) return ;
		int mid=(l+r)>>1;
		build(p*2,l,mid); build(p*2+1,mid+1,r);
	}
	inline void modify(int p,int x,int k) {
		if (tree[p].l==tree[p].r) {tree[p].sum=k; return ;}
		int mid=(tree[p].l+tree[p].r)>>1;
		if (x<=mid) modify(p*2,x,k);
		else modify(p*2+1,x,k);
		pushup(p);
	}
	inline int query(int p,int l,int r) {
		if (l<=tree[p].l&&tree[p].r<=r) return tree[p].sum;
		int mid=(tree[p].l+tree[p].r)>>1,res=0;
		if (l<=mid) res=min(3,res+query(p*2,l,r));
		if (r>mid) res=min(3,res+query(p*2+1,l,r));
		return res;
	}
}T2;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int ID,T; cin>>ID>>T;
	while (T--) {
		cin>>n>>d; int ans=0;
		for (int i=1;i<=n;i++) cin>>x[i];
		for (int i=1;i<n;i++) nxt[i]=upper_bound(x+i,x+n+1,x[i]+d)-x-1,lst[i]=lower_bound(x+1,x+i+1,x[i]-d)-x;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) mn[i][j]=INF;
		for (int l=1;l<=n;l++) {
			T1.build(1,l,n); T1.modify(1,l,l,0);
			for (int r=l;r<=n;r++) {
				mn[l][r]=T1.query(1,r,r);
				if (r+1<=nxt[r]) T1.modify(1,r+1,nxt[r],mn[l][r]+1);
			}
		}
		for (int u=1;u<=n;u++) {
			pos[n]=n;
			for (int v=n-1;v>=u;v--) {
				if (mn[u][v]==mn[u][v+1]) pos[v]=pos[v+1];
				else pos[v]=v;
			}
			T2.build(1,u,n); cnt[u][u]=1; T2.modify(1,u,1);
			for (int v=u+1;v<=n;v++) {
				if (mn[u][v]==INF) break;
				cnt[u][v]=T2.query(1,max(lst[v],u),pos[max(lst[v],u)]);
				T2.modify(1,v,cnt[u][v]); ans+=(cnt[u][v]==2);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}