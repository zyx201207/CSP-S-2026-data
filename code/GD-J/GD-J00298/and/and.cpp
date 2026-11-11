#include<bits/stdc++.h>
#define int long long
#define fin(a) freopen(a, "r", stdin)
#define fout(a) freopen(a, "w", stdout)
using namespace std;
const int N = 2e5 + 10;
int n, m, ans;
int bit[N][40];
bool fl[N];
signed main(){
	fin("and.in");
	fout("and.out");
	cin >> n >> m;
	for(int i = 1, x; i <= n; i++){
		cin >> x;
		int idx = 0;
		while(x){
			bit[i][idx++] = x & 1;
			x >>= 1;
		}
	}
	for(int j = 30; j >= 0; j--){
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(bit[i][j] && !fl[i]) cnt++;
		}
		if(cnt >= m){
			ans += (1 << j);
			for(int i = 1; i <= n; i++){
				if(!bit[i][j]) fl[i] = 1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
//10:15
/*
我怎么这么区，T2打了一个小时，T3 6min 过了，早知道先开T3了 
*/

