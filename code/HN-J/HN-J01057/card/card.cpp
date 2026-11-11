#include<iostream>
#include<queue>
using namespace std;
const int MAXN = 5e5 + 5, MAXM = 3e5 +  5;
int n, m, a[MAXN], note[MAXM], cnt[MAXN];
bool vis[MAXN], fA = true;//AÐÔÖÊ 
int main () {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] < a[i - 1]) fA = false;
	}
	if (fA) {
		for (int i = 1; i <= m; i ++) cout << i << ' ';
		return 0;
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			vis[j] = false;
			cnt[j] = 0;
		}
		for (int j = i; j <= n; j ++) {
			cnt[j] = a[j];
			if (!vis[a[j]]) vis[a[j]] = true;
			else {
				for (int k = j - 1; k >= 1; k --) {
					cnt[k] = 0;
					if (cnt[k] == a[j]) break;
				}
			}
		}
		for (int j = 1; j <= n; j ++) {
			note[cnt[j]] ++;
		}
	}
	for (int i = 1; i <= m; i ++) cout << note[i] << ' ';
	return 0;
} 
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
