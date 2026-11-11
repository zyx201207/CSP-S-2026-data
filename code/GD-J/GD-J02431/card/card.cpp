#include <iostream>

using namespace std;

const int N = 500010, M = 300010;

int a[N], arr[N], tot, c[M];

int main() {
//	freopen("card.in", "r", stdin);
//	freopen("card.out", "w", stdout);
	
	int n, m;
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		bool flag = true;
		int j;
		
		for (j = 0; j < tot; ++j) {
			if (arr[j] == a[i]) {
				flag = false;
				break;
			}
		}
		
		if (!flag) {
			tot = j;
		}
		
		arr[tot++] = a[i];
		
		for (j = 0; j < tot; ++j) {
			++c[arr[j]];
		}
	}
	
	for (int i = 1; i <= m; ++i) {
		cout << c[i] << ' ';
	}
	
	return 0;
}
