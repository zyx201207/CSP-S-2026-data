#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500010];
int ans[300010];
struct node {
	int pos, num;
}t[300010];
int main () {
//	freopen("card.in", "r", stdin);
//	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		memset(t, 0, sizeof(t)); 
		for (int j = i; j <= n; j++) {
			t[a[j]].num++;
			if (t[a[j]].pos == 0) t[a[j]].pos = j;
//			cout << j << " " << a[j] << " " << t[a[j]].num << " " << t[a[j]].pos << "\n";
			if (t[a[j]].num == 2) {
				for (int l = t[a[j]].pos; l <= j; l++) {
					t[a[l]].num--;
					if (t[a[l]].pos != 0) t[a[l]].pos = 0;
				}
				t[a[j]].num++;
				t[a[j]].pos = 0;
			}
		}
		
		for (int j = 1; j <= m; j++) {
//			cout << 1 << " ";
//			cout << "ans:" << ans[j] << " ";
			ans[j] += t[j].num;
		}
//		cout << "\n";
		
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}
//10 3
//3 1 2 1 3 2 3 1 2 1
//4 3
//1 2 1 3

