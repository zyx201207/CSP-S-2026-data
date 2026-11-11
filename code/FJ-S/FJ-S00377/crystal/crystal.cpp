#include <iostream>
#include <algorithm>
#include <cstdio>

using ll = long long;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::vector<ll> a, sum;
	ll n, m;
	std::cin >> n >> m;
	a.resize(n + 1);
	sum.resize(n + 1);
	sum[0] = 0;
	for(ll i = 1; i <= n; i++){
		std::cin >> a[i];
	}
	std::sort(a.begin() + 1, a.begin() + n + 1);
	for(ll i = 1; i <= n;i++){
		sum[i] = sum[i-1] + a[i];
	}
	ll rst = 0;
	for(ll i = 1; i <= n; i++){
		for(ll j = 1;j <= i;j++)
			if((i - j) * a[i] - m <= sum[i - 1] - sum[j - 1]){
				rst = std::max(rst, i - j + 1);
				break;
			}
	}
	std::cout << rst << std::endl;
}

