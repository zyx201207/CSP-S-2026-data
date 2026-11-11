#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int n, m, a[N], ans[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) { //n局游戏 
		vector<int> t;
		
		for (int j = i; j <= n; ++j) { //模拟每一局游戏，使用前i张牌，a[j]为当前打出的牌 
			if (j == n) { // 如果当前打出的牌为最后一张牌 
				for (int k = 1; k <= m; ++k) //查找t里是否有点数为k的牌 
					for (int ta : t)
						if (ta == k) ++ans[ta]; //有则计数 
				break;
			}
			for (size_t k = 0; k < t.size(); ++k) //循环查找 
				if (t[k] == a[j]) { //如果在已有的牌堆中找到了当前这个牌 
					for (int ta = k; ta <= t.size() + 1; ++ta) if (!t.empty()) t.pop_back(); //将当前的牌和右边的牌全部删除 
					break; //删除完成后退出 
				}
			
			t.push_back(a[j]); //打出当前牌 
		}
	}
	for (int k = 1; k <= m; ++k) cout << ans[k] << ' ';
	return 0;
} 
