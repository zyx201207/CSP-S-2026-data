#include<bits/stdc++.h>
#define ll long long
using namespace std;

// migrate
const int N = 2e6 + 10;
ll a[N], pre[N];
ll n, d, cnt_1;
void dfs_1(int s, int t, int dep, vector<int> v){
	if(v.size() == dep + 1){
		if(v.back() != t) return ;
		cnt_1 ++; 
		return ;
	}
	for(int i = s + 1; i <= pre[s]; i ++){
		v.push_back(i);
		dfs_1(i, t, dep, v);
		v.pop_back();
	}
}
bool chk(int l, int r){
	int dis = 0;
	for(int i = l; i < r;){
		dis ++;
//		if(l == 1 && r == 4) cout << i << ' ' << pre[i] << endl;
		if(pre[i] == -1) return 0;
		i = pre[i];
	}
	cnt_1 = 0;
	vector<int> v;
	v.push_back(l);
//	cout << l << ' ' << r << ' ' << dis << endl; 
	dfs_1(l, r, dis, v);
	return cnt_1 == 2;
}
void sol_1(){
	cin >> n >> d;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++){
		int l = i + 1, r = n, mid, p = -1;
		while(l <= r){
			mid = (l + r) / 2;
			if(a[mid] - a[i] <= d){
				l = mid + 1;
				p = mid; 
			}
			else r = mid - 1;
		}
		pre[i] = p;
	}
	
//	vector<int> v; v.push_back(1);
//	dfs_1(1, 4, 2, v);
//	cout << cnt_1 << endl;
//	return ;
	 
	ll cnt = 0;
	for(int l = 1; l <= n; l ++){
		for(int r = l + 1; r <= n; r ++){
			if(chk(l, r)){
				cnt ++;
			}
		}
	}
	cout << cnt << '\n';
}
int main(){
//	for(int i = 1, j = 1; i <= 9; i ++){
//		j *= i;
//		if(i == 9) cout << j;
//	} 3e6 * 9 * 9
//cout << (int)3e6 * 9 * 9 << endl;
//	freopen("1.in", "r", stdin); 

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("migrate.in", "r", stdin); 
	freopen("migrate.out", "w", stdout);
	int c, t; cin >> c >> t;
	while(t --){
		sol_1();
	}
	return 0;
} 
