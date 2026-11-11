#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6 + 10;
const int M = 1010;
const int mod = 1e9 + 7;
const double eps = 1e-9;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

int a[N];

signed main(){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int n, m;
	cin>>n>>m;
	
	for(int i = 1 ; i <= n ; i ++){
		cin>>a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	int tmp = 0, ans = 0;
	for(int l = 1, r = 1 ; r <= n ; r ++){
		if(r > 1) tmp += (r - l) * (a[r] - a[r - 1]);
		while(l <= r && tmp > m) tmp -= a[r] - a[l ++];
		ans = max(ans, r - l + 1);
	}
	cout<<ans;
	
	return 0;
}
