#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
#define rep(i, b, e) for(int i=(b);i<=(e);++i)

// maxn = 5e5, maxm = 1e18, max(abs(ai)) = 1e12
const int N = 5e5+5;
ll n, m, a[N];
int ans;

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a, a+n);
	ll w = 0; // ÐèÒªw
	int l=1, r=1; 
	while(r<n){ // l ²¹µ½ r 
		r++;
		w+=(a[r]-a[r-1])*(r-l);
//		printf("l=%d, r=%d, w=%d\n", l, r, w);
		while(w>m&&l<r){
			l++;
			w-=a[r]-a[l-1];
//			printf("l=%d, r=%d, w=%d\n", l, r, w);
		}
		ans = max(ans, r-l+1);
	}
	cout << ans;
	
	return 0;
} 
