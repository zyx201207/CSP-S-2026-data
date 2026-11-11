# include <bits/stdc++.h>
# define ll long long
using namespace std;

const int N = 2e5 + 55;

struct node {
	int a;
	char x;
	ll l, r;
};
node p[N];

int main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	
	ios::sync_with_stdio (false);
	cin.tie (0);  
	
	int n;
	cin >> n;
	
	ll last = 0;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].a >> p[i].x; 
		p[i].l = last + 1;
		p[i].r = last + p[i].a - 1;
		last = p[i].r;
	}
	
	int nodes = n;
	ll ans = 0;
	for (int i = 1; i <= nodes; i++) {
		while (1) {
			if (p[nodes].x != p[i].x) {
				if (p[i].a > p[nodes].a) {
					p[i].a -= p[nodes].a;
					p[i].l -= p[nodes].a;
					ans += p[nodes].a;
					nodes--;	
//					cout << nodes << endl;
				} else if (p[i].a == p[nodes].a) {
						ans += p[nodes].a;
						nodes--;
						break; 
				} else {
					p[nodes].a -= p[i].a;
					p[nodes].r -= p[i].a;
					ans += p[i].a;
					break;
				}
			} else {
				if (p[i].a >= p[nodes].a) {
					p[i].a -= p[nodes].a;
					p[i].l -= p[nodes].a;
					nodes--;
				} else {
					p[nodes].a -= p[i].a;
					p[nodes].r -= p[i].a;
					break;
				}
			}
		}
	}
	
	cout << ans << endl;
	return 0;
}

// 52´ºÒâ 
