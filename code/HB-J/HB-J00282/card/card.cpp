#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[500005];
long long b[300005];
long long c[500005];

int main(){
    freopen("card.in", "r", std);
    freopen("card.out", "w", std);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
		cin >> a[i];
		c[i] = 0;
	}
	for(int i = 1; i <= n; i ++){
		long long t = a[i];
		b[t] = i;
		c[t] += 1;
	}																																		
	for(int i = 1; i <= m; i ++){
		cout << b[i] << " ";
	}
    return 0;
}
