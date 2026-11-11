#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10, M = 5e3 + 10;
int n, m, a[N], lat[N], vis[N], minn[N];
int pos[N], h = 0, t = 1, q[N];
bool mp1[N];
map<int, map<int, int> > mp2;
int la[M], poss[M];
bool mp3[N];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	bool f = true;
	for (int i = 2; i <= n; i++)
		if (a[i] < a[i - 1]) {
			f = false;
			break;
		}
	if (f) {
		for (int i = 1; i <= n; i++) vis[a[i]] = i;
		for (int i = 1; i <= m; i++) cout << vis[i] << " ";
		return 0;
	}
	if (n <= 5000) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) la[j] = n + 1;
			for (int j = 1; j <= m; j++) poss[j] = n + 1; 
			for (int j = n; j >= i; j--) {
				la[j] = poss[a[j]];
				poss[a[j]] = j;
			}
			for (int j = 1; j <= m; j++) mp3[j] = 0;
			for (int j = i; j <= n; j++) {
				if (!mp3[a[j]]) vis[a[j]]++; 
				mp3[a[j]] = 1;
				if (la[j] != n + 1) j = la[j] - 1;
			}
		} 
		for (int i = 1; i <= m; i++) cout << vis[i] << " ";
		return 0;
	}
	for (int i = 0; i <= n; i++) pos[i] = n + 1;
	for (int i = 1; i <= n + 1; i++) 
		lat[i] = pos[a[i]], pos[a[i]] = i;
	for (int i = 0; i <= n + 1; i++) minn[i] = n + 1;
	for (int i = n; i >= 0; i--) minn[i] = min(minn[i + 1], lat[i + 1]);
	for (int i = n; i >= 1; i--) {
		if (mp1[a[i]] == 1) continue;
		if (minn[i] > i) vis[a[i]] += i, mp1[a[i]] = 1;
		else vis[a[i]] += i - minn[i] - mp2[a[i]][minn[i]], mp2[a[i]][minn[i]]++; 
	}
	for (int i = 1; i <= m; i++) cout << vis[i] << " ";
	return 0;
}

