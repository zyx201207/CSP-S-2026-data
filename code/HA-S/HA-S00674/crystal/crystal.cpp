#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
const ll INF = 1e18;

ll n, m;
ll a[N], b[N];
ll ans = -INF;

struct Tree{
	ll sum, l, r, lz;
}tr[N << 2];

struct SegmentTree{
	void build(int p, int l, int r){
		tr[p].l = l;
		tr[p].r = r;
		tr[p].sum = 0;
		tr[p].lz = 0;
		if(l == r){
			return;
		}
		int mid = (l + r) >> 1;
		build(p << 1, l, mid);
		build(p << 1 | 1, mid + 1, r);
		return;		
	}
	
	void push_down(int p){
		if(tr[p].lz){
			ll lz = tr[p].lz;
			tr[p << 1].lz += lz;
			tr[p << 1 | 1].lz += lz;
			tr[p << 1].sum += lz * (tr[p << 1].r - tr[p << 1].l + 1);
			tr[p << 1 | 1].sum += lz * (tr[p << 1 | 1].r - tr[p << 1 | 1].l + 1);	
			tr[p].lz = 0;
		}
	}
	
	void add(int p, int l, int r, ll k){
		if(l <= tr[p].l && tr[p].r <= r){
			tr[p].lz += k;
			tr[p].sum += (tr[p].r - tr[p].l + 1) * k;
			return;
		}
		push_down(p);
		if(l <= tr[p << 1].r)add(p << 1, l, r, k);
		if(r >= tr[p << 1 | 1].l)add(p << 1 | 1, l, r, k);
		tr[p].sum = tr[p << 1].sum + tr[p << 1 | 1].sum;
	}
	
	ll query(int p, int l, int r){
		if(l <= tr[p].l && tr[p].r <= r){
			return tr[p].sum;
		}
		push_down(p);
		ll res = 0;
		if(l <= tr[p << 1].r)res += query(p << 1, l, r);
		if(r >= tr[p << 1 | 1].l)res += query(p << 1 | 1, l, r);
		//tr[p].sum = tr[p << 1].sum + tr[p << 1 | 1].sum;
		return res;
	}
}st;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <=  n; i++){
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	ll cnt = 1, ans = 0;
	st.build(1, 1, n);
	for(int i = 2; i <= n; i++){
		if(a[i] == a[i - 1]){
			cnt++;
			ans = max(ans, cnt);
			continue;
		}
		ans = max(ans, cnt);
		cnt = 1;
		st.add(1, 1, i - 1, (a[i] - a[i - 1]));
		int l = 1, r = i, mid;
		while(l <= r){
			mid = (l + r) >> 1;
			if(st.query(1, mid, n) <= m)r = mid - 1;
			else l = mid + 1;
		}
		cnt += (i - (l));
	}
	ans = max(ans, cnt);
	cout << ans;

	return 0;	
}
