#include<iostream>

using namespace std;

const int N = 5e5 + 10, M = 3e5 + 10;
int n, m, a[N], f[N], c[M], rt[M];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		rt[a[i]] = i; f[i] = 1;
	}
	for(int i = 1; i <= n; i++){
		f[rt[a[i]]+1] += f[i]; c[a[i]] += f[i];
	}
	for(int i = 1; i <= m; i++) cout << c[i] << ' ';
	return 0;
}
