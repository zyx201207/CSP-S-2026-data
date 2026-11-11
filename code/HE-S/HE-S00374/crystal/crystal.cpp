#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 5e5 + 5;
int n, m;
int a[maxn];
int s[maxn];

int sum(int l, int r){
	return s[r] - s[l - 1];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
		 
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int ans = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
	}
	
	for(int i = 1; i <= n; i++){ //³¢ÊÔ´ÕµÚi¸ö 
		int tot = 0;
		int l = 1, r = i - 1;
		int pos = i;
		//cout << "now " << i << " \n";
		while(l <= r){
			int mid = (l + r) >> 1;
			//cout << mid <<" " << i - 1 << " :" <<(i - mid) * a[i] - sum(mid, i - 1)<<'\n';
			if((i - mid) * a[i] - sum(mid, i - 1) <= m){
				r = mid - 1;
				pos = mid;
			} else {
				l = mid + 1;
			}
		} 
		ans = max(i - pos + 1, ans);
	}
	cout << ans << endl;
	return 0;
} 
