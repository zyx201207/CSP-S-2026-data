#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e6 + 1;

int n, m, ans, a[MAXN];
bool vis[MAXN];

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 30; i >= 0; i--) {
		int cnt = 0;
		for(int j = 1; j <= n; j++) {
			if(vis[j]) {
				continue;
			}
			cnt += ((a[j] >> i) & 1);
		}
		if(cnt >= m) {
			for(int j = 1; j <= n; j++) {
				if(!((a[j] >> i) & 1)) {
					vis[j] = true;
				}
			}
			ans += (1 << i);
		}
	}
	cout << ans;
	return 0;
}
//夜风吹过几条街
//秋天瘦了满地的落叶
//于是又一整夜
//感性的句子都枯萎 凋谢
//我不想再写 
//随手撕下这一页
//原来诗跟离别
//可以没有结尾
//憔悴后悔等等这些
//于是我把诗折叠 
//邮寄出感觉 夹一束白玫瑰  你将爱退回 
