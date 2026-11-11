#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5, M = 3e5+5;
int a[N], n, m;
int sta[N], top;
bool book[M];
long long ans[M];
void debug() {
	for (int i = 1; i <= top; i++)
		cout << sta[i] << " ";
	cout << "\n";
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		//cout << "Round " << i << " :\n";
		memset(book, false, sizeof(book));
		memset(sta, 0, sizeof(sta));
		top = 0;
		for (int j = i; j <= n; j++) {
			if (book[a[j]]) {
				while (top && sta[top] != a[j])
					book[sta[top--]] = false;
			} // 之后其实不用再入栈因为保留下来相同的数实现了一样的功能
			else {
				sta[++top] = a[j];
				book[a[j]] = true;
			}
			//debug();
		}
		for (int i = 1; i <= top; i++)
			ans[sta[i]]++;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}
