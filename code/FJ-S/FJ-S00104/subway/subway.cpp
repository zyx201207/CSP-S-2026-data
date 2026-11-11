#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	int A[m+2], L[n+2][5000][2];
	for(int i = 1;i <= m;i++){
		cin >> A[i];
	}for(int i = 1;i <= n;i++){
		int s;
		cin >> s;
		for(int j = 1;j <= s;i++){
			cin >> L[i][j][0] >> L[i][j][1];
		} 
	}for(int i = 1;i <= n;i++){
		int l, r;
		cin >> l >> r;
	 	
	}
	return 0;
}
