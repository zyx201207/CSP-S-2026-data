#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n , m;
int a[N] , ans[N];
int maxd[N];
int tr[N*4] , lazy[N*4];

int cnt = 0;

void pushdown (int p) {
	lazy[p<<1] = max (lazy[p] , lazy[p<<1]);
	lazy[p<<1|1] = max (lazy[p] , lazy[p<<1|1]);
	tr[p<<1] = max (tr[p<<1] , lazy[p]);
	tr[p<<1|1] = max (tr[p<<1|1] , lazy[p]);
	lazy[p] = 0;
}

void update (int p , int l , int r , int ml , int mr , int k) {
	if (ml <= l && r <= mr) {
		tr[p] = max (tr[p] , k);
		lazy[p] = max (lazy[p] , k);
		return;
	}
	pushdown(p);
	int mid = (l + r) / 2;
	if (ml <= mid) update (p<<1 , l , mid , ml , mr , k);
	if (mid < mr) update (p<<1|1 , mid+1 , r , ml , mr , k);
	tr[p] = max (tr[p<<1] , tr[p<<1|1]);
}

int query (int p , int l , int r , int ml , int mr) {
	if (ml <= l && r <= mr) return tr[p];
	int mid = (l + r) / 2;
	int ans = 0;
	pushdown(p);
	if (ml <= mid) ans = max (ans , query (p<<1 , l , mid , ml , mr));
	if (mid < mr) ans = max (ans , query (p<<1|1 , mid + 1 , r , ml , mr));
	return ans;
}

int main () {
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout); 
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) 
		cin >> a[i];
	for (int i = 1 ; i <= n ; i++)
		maxd[a[i]] = max (maxd[a[i]] , i);
	for (int i = 1 ; i <= n ; i++) 
		if (maxd[a[i]] != i && i <= maxd[a[i]]-1)  
			update (1 , 1 , n , i , maxd[a[i]]-1 , i);
	for (int i = 1 ; i <= n ; i++) 
		ans[a[i]] = max (ans[a[i]] , i - query(1 , 1 , n , i , i));
	for (int i = 1 ; i <= m ; i++)
		printf("%d " , ans[i]);
	return 0;
}
