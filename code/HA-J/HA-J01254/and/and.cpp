#include<bits/stdc++.h>
using namespace std;
int n, m, a[200020] = {0}, curl = 0;
unsigned long long mx = 0, cur[200020] = {0};
bool b[35] = {0};
void cand(int k) {
	for(int i = 1; i <= n; i++) {
		if(!b[k]) {
			b[k] = 1;
			int l = 0;
			for(int j = 1; j <= m; j++) {
				cur[j] = cur[j - 1] & a[i + l];
				l++;
			}
			if(k == n) mx = max(mx, cur[m]);
			else cand(k + 1);
			b[k] = 0;
		}
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cur[0] = 1;
	for(int i = 0; i < 31; i++) cur[0] *= 2;
	cur[0] -= 1;
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	cand(1);
	cout << mx;
	return 0;
}

