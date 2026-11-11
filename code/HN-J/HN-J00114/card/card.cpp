#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m;
int a[N];
//int vis[M];
int cnt[M];
int vis[M];
//pair <int, int> num[M];
//void init() {
//	for (int i=1; i<=n; i++) { 
//		if (vis[a[i]] != 0) 
//			for (int j=vis[a[i]]+1; j<i; j++) 
//				num[a[j]].first = vis[a[i]], num[a[j]].second = i;
//		if (num[a[i]].second < i)
//			num[a[i]].first = num[a[i]].second = n + 1;	
//		vis[a[i]] = i;
//	}
//}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> a[i];
	for	(int i=1; i<=n; i++) {
		for (int i=1; i<=m; i++) vis[i] = 0;
		stack <int> st;
		for (int j=i; j<=n; j++) {
			if (vis[a[j]]) while (!st.empty() && st.top() != a[j]) vis[st.top()]--, st.pop();
			else vis[a[j]]++, st.push(a[j]);
		}
		for (int i=1; i<=m; i++) if (vis[i] > 0) cnt[i]++;
	}
	for (int i=1; i<=m; i++) cout << cnt[i] << ' ';
	return 0;
}
