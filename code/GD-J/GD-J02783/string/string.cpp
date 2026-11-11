#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int n;
long long ans = 0;
struct character {
	int num;
	char c;
} cnt[maxn];

int main() {
	(void)freopen("string.in", "r", stdin);
	(void)freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> cnt[i].num >> cnt[i].c;
	int i = 1, j = n;
	while(i < j) {
		if(cnt[i].num < cnt[j].num) {
			cnt[j].num -= cnt[i].num;
			if(cnt[i].c != cnt[j].c) {
				ans += (long long)cnt[i].num;
			}
			i++;
		} else if(cnt[i].num > cnt[j].num) {
			cnt[i].num -= cnt[j].num;
			if(cnt[i].c != cnt[j].c) {
				ans += (long long)cnt[j].num;
			}
			j--;
		} else {
			if(cnt[i].c != cnt[j].c) ans += (long long)cnt[i].num;
			i++;
			j--;
		}
	}
	cout << ans;
	return 0;
}
