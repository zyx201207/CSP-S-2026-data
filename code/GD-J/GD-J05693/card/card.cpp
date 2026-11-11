#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#define ll long long

using namespace std;
const int MAXN = 5e5 + 10;
int n, m;
int c[MAXN];
int ans[MAXN];
bool pan = 1;
bool pan2 = 1;
int last[MAXN];
int tong[MAXN];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) {
		cin >> c[i];
		tong[c[i]] ++;
		if(c[i] > 2) pan2 = 0;
		last[c[i]] = i;
		if(c[i] < c[i - 1]) pan = 0;
	}
	if(pan) {//A
		for(int i = 1;i <= m;i ++) {
			cout << last[i];
			if(i != m) cout << ' ';
		}
		return 0;
	}
	if(pan2) {
		int la = c[n];
		for(int i = 1;i <= n;i ++) {
			if(c[i] == la) {
				if(tong[c[i]] % 2 == 0) ans[c[i]] ++;
			}
			else {
				if(tong[c[i]] % 2 == 1) ans[c[i]] ++;
			}
		}
		for(int i = 1;i <= m;i ++) {
			cout << ans[i];
			if(i != m) cout << ' ';
		}
		return 0;
	}
	for(int st = 1;st <= n;st ++) {//n
		bool v[MAXN];
		for(int i = 1;i <= m;i ++) {
			v[i] = 0;
		}
		for(int i = st;i <= n;i ++) {//n
			if(!v[c[i]]) {
				v[c[i]] = 1;
			} else {
				int j = i - 1;
				while(c[j] != c[i]) {//n
					v[c[j]] = 0;
					j --;
				}
			}
		}
		for(int i = 1;i <= m;i ++) {
			if(v[i]) ans[i] ++;
		}
	}
	for(int i = 1;i <= m;i ++) {
		cout << ans[i];
		if(i != m) cout << ' ';
	}
	return 0;
}

