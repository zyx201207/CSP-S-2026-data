#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;

int n, ans;
long long m, d;
bool is_deng = true;
long long a[N];

int main(){
//	freopen("crystal.in", "r", stdin);
//	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%lld", a + i);
	}
		
	sort(a + 1, a + 1 + n);
	
	d = a[2] - a[1];
	for(int i = 3; i <= n; ++i){
		if(a[i] - a[i - 1] != d){
			is_deng = false;
			break;
		}
	}
	if(is_deng){
		for(int i = 1; i <= n; ++i){
			int sum = d * (i + 1) * i / 2;
			if(sum <= m)
				ans = max(ans, i + 1);
		}
		printf("%d", ans);
		return 0;
	}
	
	for(int i = n; i >= 1; --i){
		int sum = 0, cnt = 0;
		for(int j = i - 1; j >= 1; --j){
			sum += (a[i] - a[j]);
			if(sum > m) break;
			++cnt;
		}
		ans = max(ans, cnt);
	}

	printf("%d", ans + 1);
	return 0;
}
