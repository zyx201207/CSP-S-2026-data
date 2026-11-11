#include <bits/stdc++.h>

long long n, m;
int ans;
long long a[500005];
bool flag = 1;

void ans_AB(int x){
	int sum = 0;
	for(int i=2; i<=n; ++i){
		if(sum > m/x){
			std::cout << i-1;
			break;
		}
		sum += i;
	}
}

void ans_other(){
	for(int i=1; i<=n; ++i){
		for(int j=i; j<=n; ++j){
			long long sum = 0;
			for(int k=i; k<=j; ++k){
				sum += a[j] - a[k];
			}
			if(sum <= m) ans = std::max(ans, j-i+1);
		}
	}
	std::cout << ans;
}

int main(){
	std::freopen("crystal.in", "r", stdin);
	std::freopen("crystal.out", "w", stdout);
	
	std::cin >> n >> m;
	for(int i=1; i<=n; ++i)
		std::cin >> a[i];
	std::sort(a+1, a+1+n);
	
	for(int i=1; i<=n; ++i)
		if(a[i+1]-a[i] != a[2]-a[1]) flag = 0;
	
	if(flag) ans_AB(a[2]-a[1]);
	else ans_other();
}
