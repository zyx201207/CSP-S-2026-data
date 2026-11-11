#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
long long int m, min_num = 1e15, max_num = -1e15;
long long int a[500005];
long long int b[500005];
int n, ans;
bool cmp(long long int a, long long int b){
	return a < b;
}
int f(long long int goal){ // 返回最多能达到 goal 的数量 
	long long int e = m;
	int res = 0, b_len = 0;
	for(int i = 1; i <= n; ++i){
		if(a[i] < goal){
			b_len++;
			b[b_len] = goal - a[i];
		} else if(a[i] == goal){
			res++; // 不用能量就能合并
		} else {
			break;
		}
	}
	for(int i = 1; i <= b_len; ++i){
		if(e < b[i]){
			break;
		}
		res++;
		e -= b[i];
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		max_num = max(a[i], max_num);
		min_num = min(a[i], min_num);
	}
	sort(a + 1, a + n + 1, cmp); // 让一个连续区间到达一个数，让区间尽可能大
	for(long long int goal = min_num; goal <= max_num; ++goal){
		ans = max(ans, f(goal));
	}
	cout << ans;
	return 0;
}
