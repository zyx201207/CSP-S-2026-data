#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
const ll INF = 1e18;
const int mod = 1e9 + 7;
#define pii pair<int , int>

ll n , m , a[N];
ll pre[N];

int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i++){
		pre[i] = pre[i - 1] + a[i];
	}
	int ans = 1;
	for(int i = 1 ; i <= n ; i++){
		int l = 1 , r = i , mid;
		ll c = 0;
		while(l < r){
			mid = (l + r) / 2;
			c = 1ll * (i - mid + 1) * a[i] - (pre[i] - pre[mid - 1]);
			if(c <= m){
				r = mid;
			}else l = mid + 1; 
		}
		ans = max(ans , (i - r + 1));
	}
	cout << ans << '\n';
	return 0;
} 


/*
5 21
1 2 4 8 9

5 5
1 10 19 29 39

5 8
-3 -1 2 2 7
*/
