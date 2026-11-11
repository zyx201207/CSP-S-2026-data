#include<bits/stdc++.h>
#define fs first
#define sc second
#define N 200005
//#define int long long
using namespace std;

int n, m, ans;
int a[N];

signed main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	for(int k = (1 << 29);k >= 1;k >>= 1){
		int cnt = 0;
		for(int i = 1;i <= n;i++) if(a[i] & k) cnt++;
		if(cnt < m) continue;
		for(int i = 1;i <= n;i++) if(!(a[i] & k)) a[i] = 0;
		ans += k;
	}
	
	cout << ans;
	
	return 0;
	
} 
