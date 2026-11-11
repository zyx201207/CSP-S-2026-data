#include <iostream>
using namespace std;

const int N = 5e5, M = 3e5;

int card[N + 5], endpos[N + 5], mem[M + 5], res[M + 5];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> card[i];
		mem[card[i]] = i;
	}
	
	for (int i = 1; i <= n; i++) {
		endpos[i] = mem[card[i]];
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			j = endpos[j];
			res[card[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << res[i] << " ";
	}
	cout << "\n";
	
	return 0;
} 

// 10:18 48pts
// 每个点只属于一个段，算了一次之后又重复计算，是复杂度瓶颈，考虑计数 
// 11:15 算了，优化一下，让每个点直接跳到终点，每次计算O(m)，总共O(nm)，可以拿到 76pts 
// 11:19 写完了，76pts 
