#include<bits/stdc++.h>
#define int long long
#define ll long long
#define fi first
#define se second
#define rand rnd
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 500010;
struct edge{
	int v, nex;
}; 
int a[N], d[N], tr[N << 2], lazy[N << 2];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int j = n, ci = m, ans = 0;
	a[0] = -1e18 - 10;
	for(int i = n; i >= 1; i--){
		j = min(i, j);
		while(ci >= 0){
			j--;
			int del = a[i] - a[j];
			ci -= del;
//			cout << j << " " << del << " " << ci << "\n";
			if(ci < 0){
				ci += del, j++; break;
			}
		}
//		if(j == 1){
//			cout << max(i - j, ans);
//			return 0;
//		}
//		cout << j << "\n";
//		cout << ci << " " << i - j + 1 << "\n";
		ans = max(i - j + 1, ans);
		ci += (i - j) * (a[i] - a[i - 1]);
//		cout << ci << "\n\n";
		
	}
	cout << ans;
	return 0;
}
/*
这题直接看是哪一个为大水晶不就行了

然后看最接近ai的有几个
5 5
1 2 4 8 9
 

注意下标

注意时间
 
想清楚 
*/
