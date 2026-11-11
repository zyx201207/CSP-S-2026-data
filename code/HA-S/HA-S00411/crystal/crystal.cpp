#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500005;
int n, m;
int a[N];
map<int, int> cnt;
int sum[N], cnt_sum[N];
vector<int> num;
int c[N];
void init(){
	memset(c, 0, sizeof(c));
}
void add(int x, int val){
	for (int i = x; i <= (int)num.size(); i += i & (-i)){
		c[i - 1] += val * cnt[num[i - 1]];
	}
}
int query(int x){
	int res = 0;
	for (int i = x; i; i -= i & (-i)){
		res += c[i - 1];
	}
	return res;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
//	for (int i = 1; i <= n; i++){
//		cin >> a[i];
//		if (cnt[a[i]] == 0)
//			num.push_back(a[i]);
//		cnt[a[i]]++;
//		
//	}
//	sort(a + 1, a + n + 1);
//	sort(num.begin(), num.end());
//	for (int i = 1; i <= n; i++){
//		if (i == 1){
//			cnt_sum[i] = 1;
//		}
//		else{
//			cnt_sum[i] = cnt_sum[i - 1] + 1;
//		}
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++){
//		
//	}
	bool sub13 = true;
	bool sub16 = true;
	int d = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] != i)
			sub13 = false;
		if (cnt[a[i]] == 0)
			num.push_back(a[i]);
		cnt[a[i]]++;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++){
		if (i == 2){
			d = a[i] - a[i - 1];
		}
		else if (i > 2){
			if (a[i] - a[i - 1] != d){
				sub16 = false;
				break;
			}
		}
	}
	sort(num.begin(), num.end());
	if (n <= 5000){
		int ans = 0;
		for (auto v : num){
			int res = cnt[v];
			int pos = lower_bound(a + 1, a + n + 1, v) - a - 1;
			int tmpm = m;
			for (int i = pos; i >= 1; i--){
				if (tmpm >= v - a[i]){
					res++;
					tmpm -= v - a[i];
				}
				if (tmpm <= 0){
					break;
				}
			}
			ans = max(ans, res);
		}
		cout << ans;
		return 0;
	}
	if (sub13){
		int ans = 0;
		for (int i = 1; i <= n; i++){
			if (m >= i * (i - 1) / 2){
				ans = max(ans, i);
			}
			else{
				break;
			}
		}
		cout << ans;
		return 0;
	}
	if (sub16){
		int ans = 0;
		for (int i = 1; i <= n; i++){
			if (m >= d * i * (i - 1) / 2){
				ans = max(ans, i);
			}
			else{
				break;
			}
		}
		cout << ans;
		return 0;
	}
	if (n <= 10000){
		int ans = 0;
		for (auto v : num){
			int res = cnt[v];
			int pos = lower_bound(a + 1, a + n + 1, v) - a - 1;
			int tmpm = m;
			for (int i = pos; i >= 1; i--){
				if (tmpm >= v - a[i]){
					res++;
					tmpm -= v - a[i];
				}
				if (tmpm <= 0){
					break;
				}
			}
			ans = max(ans, res);
		}
		cout << ans;
		return 0;
	}
	init();
	for (int i = 0; i < (int)num.size(); i++){
		if (i == 0)
			cnt_sum[i] = cnt[num[i]];
		else
			cnt_sum[i] = cnt_sum[i - 1] + cnt[num[i]];
	}
	int ans = 0;
	for (int i = 0; i < (int)num.size(); i++){
		if (i == 0){
			ans = cnt[num[i]];
			continue;
		}
		else{
			add(1, num[i] - num[i - 1]);
			add(i + 1, num[i - 1] - num[i]);
			int pos = lower_bound(c + 1, c + n + 1, m) - c;
			int res = cnt_sum[i + 1] - cnt_sum[pos];
			int tmpm = m - (query(i + 1) - query(pos));
			res += tmpm / (num[pos + 1] - num[pos]);
			ans = max(ans, res);
		}
	}
	cout << ans;
}
