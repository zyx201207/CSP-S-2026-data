#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;

const int N = 5e5+7, INF = 0x3f3f3f3f, M = 3e5+7;

int a[N];

int n, m;
namespace sub1 {
	int tot = 0;
	int b[M], c[M], p[M];
	void solve(int k) {
		int lst = 0;
		memset(b, 0, sizeof b);
//		memset(c, 0, sizeof c);
		memset(p, 0, sizeof p);
		tot = 0;
		for (int i = k; i <= n; i++) {
			if (p[a[i]] && p[a[i]] <= tot) tot = p[a[i]];
			else b[++tot] = a[i], p[a[i]] = tot;
//			cout << tot << '\n';
//			for (int j = 1; j <= tot; j++) cout << b[j] << " \n"[j==tot];
		}
		for (int j = 1; j <= tot; j++) c[b[j]]++;
	}
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		sub1::solve(i); 
//		cout << '\n';
	}
	for (int i = 1; i <= m; i++) {
		cout << sub1::c[i] << " \n"[i==m];
	}
	return 0;
}

