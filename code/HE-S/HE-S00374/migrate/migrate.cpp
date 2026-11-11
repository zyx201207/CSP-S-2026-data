#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 2e6 + 5;
int x[maxn];

int pie(int x, int y){
	int res = 1;
	for(int i = x; i <= y; i++) res *= i;
	return res;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	while(t--){
		int n, d;
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
		if(n == 1) {
			cout << 0;
			continue;
		}
		if(c <= 2){ //尝试暴力 fail

		} else if(c == 11 || c == 12){
			int diff = x[2] - x[1];
			if(diff >= d){
				cout << 0 << '\n';
				continue;
			} else {
				int dis = d / diff;
				int cnt = ceil((double)d/dis);
				int sum = x[n] - x[1] - cnt * 1;
				int ans = pie(cnt, sum + 1) / pie(1, sum - cnt + 1);
				cout << ans << '\n';
				/*
				大致思路： 
				考虑插板法，
				每个区间长度不大于dis不小于1。总共有d/dis(向上取整)个区间。他们的和为x[n]-x[1]问有几种分法？ 
				*/
			}
		} else if(c == 13 || c == 14){
			
		}
	}
	return 0;
}
