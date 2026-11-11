#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 100; 
/*
5 5
1 2 4 8 9
8 7 5 1 0
1 = 9 - 8 - 0
c2 = 1
7 6 4 0 0
4 = 9 - 4 - 1
c2 = 5
3 2 0 0 0
2 = 9 - 2 - 5
1 0 0 0 0
1 = 9 - 1 - 7

 1 2 4 1


5 8
-3 -1 2 2
10 8  5 5 = 28
5 3 0 0 = 8
*/
int n;
ll m, a[MAXN], b[MAXN], cnt[MAXN];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	ll s = 0;
	for(int i = 1; i <= n; i++){
		s += a[n] - a[i];
//		b[i] = a[n] - a[i]; 
	}
	ll cur1 = 0, cur2 = 0;
	for(int i = n - 1; i >= 0; i--){
//		s = 0;
//		for(int j = 1; j <= i; j++){
//			s += b[j];
//		}
		if(s <= m){
			cout << i + 1 << '\n';
			return 0;
		}
		cur1 = a[n] - a[i] - cur2;
//		if(s - 1ll * i * cur1 <= m){
//			int x = 0;
//			while(x * cur1 <= s) x++;
//			cout << i + x << '\n';
//			return 0;
//		}
		s -= 1ll * i * cur1;
		cur2 += cur1;
//		for(int j = 1; j <= i; j++){
//			b[j] -= b[i];
//		}
	}
	cout << 1;
	return 0;
}
