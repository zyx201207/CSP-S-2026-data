#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;	
int n, m;
int a[N];
int ans = 0;
int st[32][N];
vector<int> v;
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		for(int j = 1; j <= 31; j ++){
			st[j][i] = (a[i] >> (j - 1) & 1);
		}
		v.push_back(i);
	}
	vector<int> tmp;
	for(int i = 31; i >= 1; i --){
		int cnt = 0;
		for(auto j : v){
			if(st[i][j]) cnt ++;
		}
		if(cnt >= m){
//			cout << (1 << (i - 1)) << endl;
			ans += (1 << (i - 1));
			tmp.clear();
			tmp = v;
			v.clear();
			for(auto j : tmp){
				if(st[i][j]) v.push_back(j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
/*
5 3
31 3 1 15 7

4 2
3 15 12 12
*/

