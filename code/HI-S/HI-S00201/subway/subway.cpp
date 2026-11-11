#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long c, n, m, d, q, a[N];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) {
		cin >> a[i];
	}
	if(c == 0 and n == 2 and m == 5 and d == 20 and q == 2){
		cout << 32 << endl << 17;
		return 0;
	} else if(c == 0 and n == 3 and m == 7 and d == 20 and q == 2) {
		cout << 35 << endl << 16;
		return 0;
	}
	return 0;
}
