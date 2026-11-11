#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>



size_t down(std::vector<long long>& a, size_t i,size_t j,size_t d) {
	size_t ans = 0;
	if(i + 1 == j)return (a[j] - a[i] <= d);
	for(size_t k = i + 1; k < j; k++){
		size_t x= down(a, k ,j,d);
		size_t y= down(a, i ,k,d);
		if(x>0&&y>0)ans += x + y;
	}
	return ans;
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	{
		int c;
		std::cin >> c;
	}
	size_t T;
	std::cin >> T;
	while(T--){
		std::vector<long long> a;
		size_t n, d, sum = 0;
		std::cin >> n >> d;
		for(size_t i = 1;i <= n;i++) {
			long long v;
			std::cin >> v;
			a.push_back(v);
		}
		for(size_t i = 1;i <= n;i++){
			for(size_t j = i + 2;j <= n;j++){
				if(down(a,i,j,d) == 2) sum++;
			}
		}
		std::cout << sum << '\n';
	}
}

