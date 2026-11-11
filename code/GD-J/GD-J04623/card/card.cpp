#include <iostream>
#include <cstring>
using namespace std;

const int N = 5e5 + 5, M = 3e5 + 5;
int pre[N], a[N], n, m;
int num[M];
int vis[5005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	bool f = 1;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] < a[i - 1]) f = 0;
	}
	if(f == 1) {
		for(int i = 1; i <= n; i++) num[a[i]]++;
		int last = 0;
		for(int i = 1; i < M; i++) {
			if(num[i]) {
				cout << num[i] + last << ' ';
				last += num[i];
			}
		}
		return 0;
	}
	if(m == 1) {
		cout << n;
		return 0;
	}
	if(m == 2) {
		int x, y;
		for(int i = 1; i <= n; i++) {
			if(x == 0) x = a[i];
			if(x != 0 && a[i] != x) y = a[i];
		}
		int cnt_x, cnt_y;
		for(int i = 1; i < n; i++) {
			if(a[i] == x) cnt_x++;
			else cnt_y++;
		}
		if(cnt_x == a[n]) cnt_x += n;
		else cnt_y += n;
		if(x > y) swap(cnt_x, cnt_y);
		cout << cnt_x << ' ' << cnt_y;
		return 0;
	}
	for(int i = 2; i <= n; i++) {
		for(int j = i - 1; j >= 1; j--) {
			if(a[i] == a[j]) {
				pre[i] = j;
				break;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) vis[j] = 1;
		for(int j = i; j <= n; j++) {
			if(pre[j] < i) continue;
			if(!vis[pre[j]]) continue;
			for(int k = pre[j]; k < j; k++) vis[k] = 0;
		}
		for(int j = i; j <= n; j++)
			if(vis[j]) num[a[j]]++;
	}
	for(int i = 1; i < M; i++) {
		if(num[i]) cout << num[i] << ' ';
	}
}
