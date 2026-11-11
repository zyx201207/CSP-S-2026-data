#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, ans = 0;
	cin >> n >> m;
	vector<bool> b(n + 1, 0); 
	vector<int> a(n + 1);
	for(int i=1; i<=n; i++) cin >> a[i];
	int bitcnt = 30;
	while(bitcnt >= 0){
		vector<int> cnt(31, 0);
		for(int i=1; i<=n; i++){
			if(b[i]) continue;
			int t = a[i], j = 0;
			while(t){
				cnt[j++] += t % 2;
				t >>= 1;
			}
		}
		while(bitcnt >= 0 && cnt[bitcnt] < m) bitcnt--;
		if(bitcnt >= 0){
			for(int i=1; i<=n; i++){
				if((a[i] & (1 << bitcnt)) == 0) b[i] = 1;
			}
			ans += 1 << bitcnt;
		}
		bitcnt--;
	}
	cout << ans;
    return 0;
}
