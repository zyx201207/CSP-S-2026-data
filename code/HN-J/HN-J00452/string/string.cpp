// 欲买桂花同载酒，终不似少年游
// 这道题应该可以用双指针做 
// 其实朴素暴力也可以，但 1e9 的数据有点限制了 tangzhuo 的发挥
// （所以 tangzhuo 在那个考场） ，他现在应该在暴力了
// T1 花了我一个小时 - emm...

/* begin - 9.23 */ 
#include<bits/stdc++.h>
using namespace std;	

const int N = 2e5 + 5;
int a[N];
char c[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	int n; cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> c[i];
	}
	
	unsigned long long ans = 0; 
	int lp = 1;
	int rp = n;
	while(lp < rp) {
		if(c[lp] != c[rp]) {
			ans += min(a[lp], a[rp]);
		}
		int dlc666 = min(a[lp], a[rp]);
		// %%% dlc666
		a[lp] -= dlc666;
		a[rp] -= dlc666;
		
		if(a[lp] == 0) lp++;
		if(a[rp] == 0) rp--; 
	}
	
//	cerr << ans << endl;
	cout << ans << endl;
	return 0;
}
/* end - 9:39 */ 

/*
3
2 a
2 b
1 c
*/
