#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m;
int a[N];
int A = 1;
int to_5k[3005], a_5k[5005], ans_5k[3005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		
		if (a[i] < a[i - 1]) A = 0;
	}
	
	if (114514) { // £¿ 
		
		for (int t = 1; t <= n; t++) {
			for (int i = 1; i <= n; i++) {
				to_5k[i] = a_5k[i] = 0;
			}
			int len = 0;
			
			for (int i = t; i <= n; i++) {
				if (!to_5k[a[i]]) {
					a_5k[++len] = a[i];
				} else {
					len = to_5k[a[i]];
					a_5k[++len] = a[i];
				}
				to_5k[a[i]] = i;
			}
			unordered_map<int, bool> mp;
			for (int i = i; i <= len; i++) {
				//cout << a_5k[i] << ' ';
				if (!mp[a_5k[i]]) ans_5k[a_5k[i]]++;
				mp[a_5k[i]] = 1;
			}
			//cout << endl;
		}
		for (int i = 1; i <= m; i++) {
			cout << ans_5k[i] << " ";
		}
	}
	return 0;
}

/*
4 3
1 2 1 3


10 3
3 1 2 1 3 2 3 1 2 1

*/ 
