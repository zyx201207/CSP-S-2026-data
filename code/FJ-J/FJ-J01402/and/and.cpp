#include <iostream>
using namespace std;
typedef long long ll;
ll ans, a[(int)(2e5 + 1)], f[(int)(2e5 + 1)]; 
int main(){
	/*
	朴素算法: DP
	f[i]表示前 i 个数能取到的最大值
	状态转移: f[i] = max(f[i], f[k] & a[i])
	边界: 第 1 轮所有数最大值为其本身 
	倒序循环 
	
	特殊性质1：输出最大值
	特殊性质2：算出所有数按位与的结果
	特殊性质3：双重循环取最大值 
	*/
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (m == 1){
		for (int i = 1; i <= n; i++)
			ans = max(ans, a[i]);
	}else if (m == n){
		ans = a[1];
		for (int i = 2; i <= n; i++)
			ans &= a[i];
	}else if (m == 2){
		for (int i = 1; i < n; i++)
			for (int j = (i + 1); j <= n; j++)
				ans = max(ans, (a[i] & a[j]));
	}else{
		int x;
		for (int i = 1; i <= n; i++)
			f[i] = a[i];
		for (int i = 2; i <= m; i++)
			for (int j = n; j >= i; j--){
				x = f[j];
				f[j] = -1;
				for (int k = (i - 1); k < j; k++)
					f[j] = max(f[j], (f[k] & x));
			}
		ans = -1;
		for (int i = m; i <= n; i++)
			ans = max(ans, f[i]);
	}
	cout << ans;
}
