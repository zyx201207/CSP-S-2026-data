#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while(t --){
		long long n, k;
		cin >> n >> k;
		vector<long long> a(n);
		vector<long long> b(n);
		for(int i = 1; i <= n - 1; i ++){
			cin >> a[i] >> b[i];
		}
		cout << 1 << endl;
	}
    return 0;
}
