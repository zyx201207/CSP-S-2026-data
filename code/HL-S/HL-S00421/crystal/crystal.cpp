#include <iostream>
#include <algorithm>
#include <queue>
using namespace std; 
long long n, m, ans = 0; 
const int SIDE = 5e5 + 5; 
const int Rev = 1e9; 
long long crystal[SIDE]; 
long long pre[SIDE]; 
priority_queue<int> Qneed; 

int main() {
	freopen("crystal3.in", "r", stdin); 
	freopen("crystal3.out", "w", stdout); 
	
	cin >> n >> m; 
	for (int i = 1; i <= n; i++) {
		cin >> crystal[i]; 
	}
	
	if (n <= 5000) {
		sort(crystal + 1, crystal + n + 1); 
		
		for (int c = 1; c <= n; c++) {
			long long cnt = 1; 
			for (int j = 1; j <= c; j++) {
				int temp = crystal[c] - crystal[j]; 
				Qneed.push((Rev - temp)); 
			}
			
			while (!Qneed.empty()) {
				int Top = Rev - Qneed.top(); 
				Qneed.pop(); 
				if (m >= Top) {	
					m -= Top; 
					cnt++; 
				} else {
					break; 
				}
			}
			
			ans = max(ans, cnt); 
		}
		cout << ans; 
	} else {
		int t = crystal[2] - crystal[1]; 
		pre[1] = 0; 
		for (int i = 2; i <= n; i++) {
			pre[i] = pre[i - 1] + t; 
		}
		for (int i = 1; i <= n; i++) {
			if (m >= pre[i] && m < pre[i + 1]) {
				cout << i; 
				break; 
			}
		}
	}

	
	fclose(stdin); 
	fclose(stdout); 
	return 0; 
}

/*

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/