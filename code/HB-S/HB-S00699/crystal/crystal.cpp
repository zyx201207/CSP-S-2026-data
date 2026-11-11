#include <iostream>
#include <cstdio>
#include <algorithm>

const int N = 5e5 + 10;
int n;
long long m;
long long a[N];
long long c[N];

inline long long get_add(int l, int r){ // [l, r]
	return c[r] - c[l - 1];
}

inline long long get_need_w(int l, int r, long long target){
	return (r - l + 1) * target - get_add(l, r);
}

int find(int end, int k){  // [l, r] -> k
	int l=1, r=end;
	while(l < r){
		int mid = (l + r) >> 1;
		int res = get_need_w(mid, end, k);
		if(res <= m){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	return l;
}

int main(){
	std::freopen("crystal.in", "r", stdin);
	std::freopen("crystal.out", "w", stdout);
	std::cin >> n >> m;
	for(int i=1; i<=n; i++) std::cin >> a[i];
	std::sort(a+1, a+n+1);
	for(int i=1; i<=n; i++){
		c[i] = a[i] + c[i-1];
	}
	int res = 1;
	for(int i=2; i<=n; i++){
		res = std::max(i - find(i-1, a[i]) + 1, res);
		//std::cout << i << " " << i - find(i, a[i]) + 1 << std::endl;
		//std::cout << i << " " << get_need_w(1, i, a[i]) << std::endl;
		//std::cout << i << " " << c[i] << std::endl;
	}
	std::cout << res;
	return 0;
}