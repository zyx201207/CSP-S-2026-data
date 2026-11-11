#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 1;
int cnt[N], pos[N], f, l, a[N];
bool flag[N], s[N];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int mini, maxi;
	for (int i = 0; i < n; i++) {
		mini = n, maxi = -1;
		memset(s, 0, sizeof(s));
		memset(pos, -1, sizeof(pos));
		memset(flag, 0, sizeof(flag));
		for (int j = i; j < n; j++) {
			if (s[pos[a[j]]]) pos[a[j]] = j;
			if (flag[a[j]] == 0) {
				flag[a[j]] = 1;
				pos[a[j]] = j;
			}
			else {
				for (int k = pos[a[j]]; k < j; k++) {
					s[k] = 1;
				}
				pos[a[j]] = j;
			}
		}
		for (int j = i; j <n; j++) {
			if (!s[j]) {
				cnt[a[j]]++;
			}
		}
	}
	for (int i = 1; i <= m; i++) 
		cout << cnt[i] << ' ';
	return 0;
}

