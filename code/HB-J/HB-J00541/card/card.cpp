#include<bits/stdc++.h>
using namespace std;
#define fo(i, a, b) for(int i = (a); i <= (b); i++)
#define ro(i, a, b) for(int i = (a); i >= (b); i--)
//#define int long long 

const int N = 5e5 + 5, M = 3e5 + 5;

int n, m;
int a[N];


int q[N], hh, tt;

int ans[N];

void wk(int l, int r) {
	hh = l, tt = l;
	fo(i, l, n) {
		for(int j = hh; j < tt; j++) {
			if(q[j] == a[i]) {
				tt = j;
			}
		}
		q[tt++] = a[i];
	}
	for(int j = hh; j < tt; j++) ans[q[j]]++;
}


signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	fo(i, 1 ,n) {
		cin >> a[i];
	}
	if(n <= 500 && m <= 200) {
		
	
	fo(i, 1, n) {
		wk(i, n);
	}
	fo(i, 1, m) cout << ans[i] << " ";
	return 0;
	
	
	}
	
	fo(i, 1, n) {
		if(a[i] == a[i + 1]) continue;
		else cout << i << " ";
	}
	
	
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
