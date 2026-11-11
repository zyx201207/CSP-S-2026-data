#include <iostream>
#define N 500005
#define M 300005
using namespace std;

int n, m, a[N], p[M], rr[N], pr[N], lst[N], flg[M], ans[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) p[i] = n + 1;
	for(int i = n; i >= 1; i--) {
		if(p[a[i]]) lst[i] = p[a[i]], p[a[i]] = i;
	}
	for(int i = 1; i <= n; i++) {
//		cout << lst[i] << " ";
		rr[i] += rr[i - 1];
		pr[i] = rr[i] + i;
		if(lst[i] != n + 1) {
			rr[i + 1] -= pr[i];
			rr[lst[i]] += pr[i];
		}
//		cout << pr[i] << " "; 
	}
	for(int i = n; i >= 1; i--) if(!flg[a[i]]) flg[a[i]] = 1, ans[a[i]] = pr[i]; 
	for(int i = 1; i <= m; i++) {
		cout << ans[i];
		if(i != m) cout << " ";
	}
	return 0;
}

// Green

// CSP ¼õ J ³ýÒÔ S ºÜÄÑ 
