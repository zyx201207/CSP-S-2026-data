#include<bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 10;
long long a[N];
int n, m;

bool cmp(long long x, long long y){
	return x > y;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	long long mx = -1;
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		mx = max(mx, a[i]);
	}if(m == 1){
		printf("%lld", mx);
		return 0;
	}else if(m == n){
		long long ans = a[1];
		for(int i = 2; i <= n; i++) ans = (ans&a[i]);
		printf("%lld", ans);
		return 0;
	}else if(m == 2){
		long long mxx = 1;
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				mxx = max(mxx, (a[i]&a[j]));
			}
		}printf("%lld", mxx);
		return 0;
	}else{
		sort(a+1, a+n+1, cmp);
		long long sum = a[1];
		for(int i = 2; i <= m; i++){
			//cout << a[i] << " ";
			sum = (sum&a[i]);
			//cout << sum << " ";
		}printf("%lld", sum);
		return 0;
	}
	return 0;
}
