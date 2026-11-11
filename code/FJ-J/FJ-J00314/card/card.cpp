#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 10;
int n, m;
int a[N], d[N], b[N], c[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	if(m == 1){
		cout << n;
		return 0;
	}
	return 0;
}
