#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m, a[N], ans;
vector<int> b;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) b.push_back(i);
	for(int k = 30; k >= 0; k--){
		vector<int> bnxt;
		for(int i = 0; i < b.size(); i++) if((a[b[i]] >> k) & 1) bnxt.push_back(b[i]);
		if(bnxt.size() >= m) swap(bnxt, b), ans ^= (1 << k);
	}
	cout << ans;
	return 0;
}
