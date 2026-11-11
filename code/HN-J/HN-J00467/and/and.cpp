#include <bits/stdc++.h>
using namespace std;

struct num{
	int p;
	int cnt;
	int d;
} a[200005]; 

bool cmp(num x, num y){
	if(x.d != y.d){
		return x.d > y.d;
	} else {
		return x.cnt > y.cnt;
	}
} 

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i].p;
		int x = a[i].p;
		while (x > 0){
			if(x & 1){
				a[i].cnt++;
			}
			a[i].d++;
			x >>= 1;
		}
	} 
	sort(a + 1, a + n + 1, cmp);
	int ans = pow(2, 30) - 1;
	for(int i = 1; i <= m; i++){
		//cout << a[i].p << ' ';
		ans &= a[i].p;
	} 
	cout << ans;
	
	
	return 0;
} 

