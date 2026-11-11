#include <bits/stdc++.h>
using namespace std;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int maxn = 5e5 + 5;


int n, m;
int a[maxn];
int h[maxn];//记录第i张牌的位置 
int k;
int ans[maxn];//记录答案 
int c[maxn];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	AC;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		//第i局游戏
		k = 0;
		for (int j = 1; j <= n; ++j) {
			
			h[i] = 0;
		}
		for (int j = i; j <= n; ++j) {
			++k;
//			cout << 111 << "\n";
			if (h[a[j]] != 0) {
				int t = k;
				for (int l = c[h[a[j]]]; l < j; ++l) {
					h[a[l]] = 0;
					--t;
				}
				for (int l = t; l < k; ++l) c[l] = 0;
				k = t;
			}
			h[a[j]] = k;
			c[k] = a[j];
		}
		for (int j = 1; j <= k; ++j) {
			++ans[c[i]];
			cout << c[i] << "\n";
		}
		cout << "\n";
	}
	for (int i = 1; i <= m; ++i) {
		cout << ans[i] << " ";
	}
	
	//哦不不不不不，我无疑是愤怒的，T4绝对是0 
	//真服了，没时间写了，现在就2分钟了，T2差点炸了 
	return 0;
}
