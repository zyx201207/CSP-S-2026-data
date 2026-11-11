#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long n, m, ans;
long long a[N];
long long cnt[50];//每一位有多少个一
vector<long long> num;
vector<long long> vis[100];

void dig(long long x, long long lim) {
	num.clear();
	long long k = x;
	while(x) num.push_back(x % 2), x /= 2;
	if(num.size() < lim) lim = num.size(); 
	for(long long i = 0;i < lim;i++) {
		if(num[i] == 1) {
			vis[i+1].push_back(k), cnt[i+1]++;
		}
	}
} 

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++) cin >> a[i], dig(a[i], 50);
	for(long long i = 31;i >= 1;i--) {
		if(cnt[i] >= m) {
			for(long long j = 1;j <= 40;j++) cnt[j] = 0;
			for(long long j = i - 1;j >= 1;j--) vis[j].clear();
			for(auto v : vis[i]) dig(v, i-1);
			ans += (1 << (i-1));
		}
	}
	cout << ans << '\n';
	return 0;
}
