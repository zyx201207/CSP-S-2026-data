#include <bits/stdc++.h>
using namespace std;
#define D(a) cout << #a << " : " << a << " "
#define nl cout << "\n"
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
int c,t;
void solve1(){
	int n,d; cin >> n >> d; vector<int>x(n+10);
	for (int i=1;i<=n;i++) cin >> x[i];
	vector <vector<int> >dis(n+10,vector<int>(n+10,inf));
	vector <vector<int> >cnt(n+10,vector<int>(n+10,0));
	for (int i=1;i<=n;i++) dis[i][i] = 0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (i == j) continue;
			if (abs(x[i] - x[j]) <= d){
				dis[i][j] = 1; cnt[i][j] = 1;
			}
		}
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (dis[i][j] == dis[i][k] + dis[k][j]){
					cnt[i][j] += cnt[i][k] * cnt[k][j];
				}
				else if (dis[i][j] > dis[i][k] + dis[k][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
					cnt[i][j] = cnt[i][k] * cnt[k][j];
				}
			}
		}
	}
	int ans = 0;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			if (cnt[i][j] == 2){
				ans ++;
			}
		}
	}
	cout << ans << "\n";
}
struct SGT{ // »¹Ã»¹Ü cnte2 
	struct TREE{
		int dp,cnt,lazydp,lazycnt,cnte2,len;
		TREE operator + (const TREE &t) const{
			return {max(dp,t.dp),cnt,0,0,cnte2+t.cnte2,len+t.len};
		}
	};vector<TREE>tr;
	void init(int n){
		tr.resize(n*4+10);
	}
	int ls(int p) {return p * 2;}
	int rs(int p) {return p * 2 + 1;}
	int mid(int l,int r) {return (l + r) / 2;}
	void pd(int p){
		if (tr[p].lazydp){
			tr[ls(p)].lazydp = tr[rs(p)].lazydp = tr[p].lazydp;
			tr[ls(p)].dp = tr[rs(p)].dp = tr[p].lazydp;
			tr[p].lazydp = 0;
		}
		if (tr[p].lazycnt){
			tr[ls(p)].lazycnt += tr[p].lazycnt;
			tr[rs(p)].lazycnt += tr[p].lazycnt;
			tr[ls(p)].cnt += tr[p].lazycnt * tr[ls(p)].len;
			tr[rs(p)].cnt += tr[p].lazycnt * tr[rs(p)].len;
			tr[p].lazycnt = 0;
		} 
	}
	void build(int p,int l,int r){
		tr[p].dp = inf; tr[p].cnt = 0; tr[p].lazydp = 0; tr[p].lazycnt = 0;tr[p].cnte2 = 0; tr[p].len = 1;
		if (l == r){
			return;
		}
		build(ls(p),l,mid(l,r));
		build(rs(p),mid(l,r)+1,r);
		tr[p] = tr[ls(p)] + tr[rs(p)]; 
	}
	void upddp(int p,int l,int r,int L,int R,int c){
		if (L <= l && r <= R){
			tr[p].dp = c; tr[p].lazydp = c; 
			return;
		}
		pd(p);
		if (L <= mid(l,r)) upddp(ls(p),l,mid(l,r),L,R,c);
		if (mid(l,r) < R) upddp(rs(p),mid(l,r)+1,r,L,R,c);
		tr[p] = tr[ls(p)] + tr[rs(p)];
	}
	void updcnt(int p,int l,int r,int L,int R,int c){
		if (L <= l && r <= R){
			tr[p].cnt += tr[p].len * c; tr[p].lazycnt += c; return;
		}
		pd(p);
		if (L <= mid(l,r)) updcnt(ls(p),l,mid(l,r),L,R,c);
		if (mid(l,r) < R) updcnt(rs(p),mid(l,r)+1,r,L,R,c);
		tr[p] =  tr[ls(p)] + tr[rs(p)];
	}
	int bindp(int p,int l,int r,int L,int R,int c){
		if (l == r){
			return l;
		}
		pd(p);
		if (tr[ls(p)].dp >= c) return bindp(ls(p),l,mid(l,r),L,R,c);
		else return bindp(rs(p),mid(l,r)+1,r,L,R,c);
	}
	int bindp2(int p,int l,int r,int L,int R,int c){
		if (l == r){
			return l;
		}
		pd(p);
		if (tr[rs(p)].dp >= c) return bindp2(rs(p),mid(l,r)+1,r,L,R,c);
		else return bindp2(ls(p),l,mid(l,r),L,R,c);
	}
	int qrycnt(int p,int l,int r,int x){
		if (l == r) return tr[p].cnt;
		pd(p);
		if (x <= mid(l,r)) return qrycnt(ls(p),l,mid(l,r),x);
		else return qrycnt(rs(p),mid(l,r)+1,r,x);
	}
	int qrydp(int p,int l,int r,int x){
		if (l == r) return tr[p].dp;
		pd(p);
		if (x <= mid(l,r)) return qrydp(ls(p),l,mid(l,r),x);
		else return qrydp(rs(p),mid(l,r)+1,r,x);
	}
};
void solve2(){
	SGT sgt;
	int n,d; cin >> n >> d; vector <int> x(n+10);
	for (int i=1;i<=n;i++) cin >> x[i];
	sgt.init(n);
	int ans = 0;
	for (int i=1;i<=n;i++){
		sgt.build(1,i,n);
		sgt.upddp(1,i,n,i,i,0);
		sgt.updcnt(1,i,n,i,i,1);
		for (int j=i;j<n;j++){
			int R = upper_bound(x.begin() + 1,x.begin()+1+n,x[j] + d) - x.begin() - 1;
			int L = sgt.bindp(1,i,n,j+1,n,sgt.qrydp(1,i,n,j) + 1);
			int R2 = sgt.bindp2(1,i,n,j+1,n,sgt.qrydp(1,i,n,j) + 1);
			if (sgt.qrydp(1,i,n,L) <= sgt.qrydp(1,i,n,j)) continue;
			if (L > R) continue;
//			D(i); D(j); D(L); D(R); D(R2); nl;
			sgt.upddp(1,i,n,L,R,sgt.qrydp(1,i,n,j) + 1);
			sgt.updcnt(1,i,n,L,R,1);
			if (sgt.qrydp(1,i,n,R2) == sgt.qrydp(1,i,n,j) + 1) sgt.updcnt(1,i,n,L,R2,sgt.qrycnt(1,i,n,j) - 1);
			
//			for (int k=1;k<=n;k++) cout << sgt.qrycnt(1,i,n,k) << " ";
//			nl;
		}
		
		int res = 0;
		for (int j=i;j<=n;j++){
			res += (sgt.qrycnt(1,i,n,j) == 2);
//			if (sgt.qrycnt(1,i,n,j) == 2){
//				D(i); D(j); nl;
//			}
		}
		ans += res;
	}
	cout << ans << "\n";
}
void solve3(){
	int ans = 0;
	int n,d; cin >> n >> d;
	vector<int>x(n+10);
	for (int i=1;i<=n;i++) cin >> x[i];
	for (int i=1;i<=n;i++){
		int p = upper_bound(x.begin()+1,x.begin()+1+n,x[i] + d) - x.begin();
		ans += (n - p + 1);
	}
	cout << ans << "\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> c >> t;
	if (1 <= c && c <= 6){
		while (t--) solve1();
	}
	else if (13 <= c && c <= 14){
		while (t--) solve3();
	}
	else{
		while (t--) solve2();
	}
	return 0;
}
