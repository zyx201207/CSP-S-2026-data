#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n;
int len[N], sum[N], cnt[N][26], pos_cnt[26], oth[26];
char a[N];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> n;
//	for (int i = 0; i < 26; i++) pos_cnt[i] = n + 1;
	for (int i = 1; i <= n; i++) cin >> len[i] >> a[i];
	int summ = 0;
	for (int i = 1; i <= n; i++) summ += len[i];
	if (summ <= 20000000) {
		string b = "";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= len[i]; j++) b += a[i];
		}
		int anss = 0;
		for (int i = 0; i < b.size(); i++)
			if (b[i] != b[b.size() - i]) ++anss;
		cout << anss;
		return 0;
	}
	for (int i = n; i >= 1; i--) {
		sum[i] = sum[i + 1] + len[i];
		for (int j = 0; j < 26; j++) cnt[i][j] = cnt[i + 1][j];
		cnt[i][a[i] - 'a'] += len[i];
	}
	int pos = n, jian = 0, jian2 = 0, last_pos = n + 1, last_char = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i >= pos) break;
		int l = i + 1, r = pos, pos2 = pos + 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (sum[mid] - jian <= len[i]) r = mid - 1, pos2 = mid;
			else l = mid + 1;
		}
		pos = pos2;
//		cout << pos2 << " " << jian << " " << jian2 << " " << i << "\n";
		if (pos + 1 != pos2 && len[i] == sum[pos] - jian) {
			ans += sum[pos] - cnt[pos][a[i] - 'a'] - jian + cnt[last_pos][a[i] - 'a'] + oth[a[i] - 'a'];
//			cout << pos << " " << sum[pos] << " " << cnt[pos][a[i] - 'a'] << " " << jian << " " << jian_cnt[a[i] - 'a'] << "\n";
//			cout << a[i] << " " << a[pos] << " " << sum[pos] << " " << jian << " " << pos << " " << pos_cnt[a[i] - 'a'] << "\n"; 
			last_pos = pos;
			oth[last_char] = 0;
			last_char = 0;
			jian += sum[pos] - jian;
			--pos;
		}
		else if (pos2 == pos + 1 || len[i] > sum[pos] - jian) {
			int tmp = sum[pos] - jian;
			if (pos2 == pos + 1) tmp = 0;
			if (pos2 != pos + 1) {
				ans += sum[pos] - cnt[pos][a[i] - 'a'] - jian + cnt[last_pos][a[i] - 'a'] + oth[a[i] - 'a']; 
				last_pos = pos;
				oth[last_char] = 0;
				last_char = 0;
				jian += sum[pos] - jian;
			}
			--pos;
			if (pos == i) continue;
			int yu = len[i] - tmp;
			oth[last_char] = 0;
			last_char = 0;
			if (a[pos] != a[i]) ans += yu;
			else oth[a[i] - 'a'] = yu, last_char = a[i] - 'a';
			jian += yu;
		}
	}
	cout << ans;
	return 0;
}
/*
3
1 a
4 b
4 c
*/
