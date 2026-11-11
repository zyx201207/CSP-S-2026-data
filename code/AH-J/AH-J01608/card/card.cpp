#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
int a[N], b[N], ans[N], c[N];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	if(n <= 500){
		for(int i = 1; i <= n; i ++){
			memset(b, 0, sizeof b);
			int tp = 0, fp = 0;
			for(int j = i; j <= n; j ++)
				b[++ tp] = a[j];
			for(int j = 1; j <= tp; j ++){
				for(int k = 1; k <= fp; k ++){
					if(c[k] == b[j]){
						for(int q = k; q <= fp; q ++)
							c[q] = 0;
						fp = k-1;
					}
				}
				c[++ fp]= b[j];
			}
			for(int j = 1; j <= fp; j++)
				ans[c[j]] ++;
		}
		for(int i = 1; i <= m; i ++) cout << ans[i] << ' ';
	} 
	else{
		int p = 1;
		for(int i = 2; i <= n; i ++){
			if(a[i] != a[i-1]) cout << i-1 <<' ';
		}
		cout << n;
	}
	return 0;
}
/*
1 1 2 2 3
1 2 3
1 2 3
2 3 
*/ 
