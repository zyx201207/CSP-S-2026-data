#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 50 , M = 3e5 + 50;
int n , m;
int a[N] , d[N] , l[M] , ll[M] , cnt[M] , s[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] , d[i] = 0;
	for(int i = 1 ; i <= m ; i++) l[i] = -1;
	for(int i = n ; i >= 1 ; i--) {
		d[i]++;
		d[n+1]--;
		int j = a[i];
		if(l[j] != -1) {
			d[i] -= 1;
			d[l[j]] += 1;
		}
		l[j] = i;
	}
	for(int i = 1 ; i <= n ; i++) {
		s[i] = s[i-1] + d[i];
		cnt[a[i]] += s[i];
	}
	for(int i = 1 ; i < m ; i++) {
		cout << cnt[i] << ' ';
	}
	cout << cnt[m];
	return 0;
}

