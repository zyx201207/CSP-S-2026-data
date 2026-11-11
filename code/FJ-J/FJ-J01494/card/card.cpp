#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
const int M = 3e5 + 5;
int n, m, a[N], ans[N];
struct c{
	int times, num;
}cnt[M];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]].times++;
		cnt[a[i]].num = i;
	}
	for (int i = 1; i <= n; i++) {
		cnt[a[i - 1]].times--;
		for (int j = i; j <= n; j++) {
			if (cnt[a[j]].times >= 2) j = cnt[a[j]].num;
			ans[a[j]]++;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << ans[a[i]] << " ";
	return 0;
}
