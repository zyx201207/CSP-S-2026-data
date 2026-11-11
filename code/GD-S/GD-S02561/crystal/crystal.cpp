#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long a[N];
long long sum[N];

bool cmp(long long x, long long y){
	return x > y;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n;
	long long m;
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	
	sort(a + 1, a + n + 1, cmp);
	
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
	} 
	
	long long ans = 1;
	for(int i = 1; i <= n; i++){
		long long cnt = 1;
		//into i
		long long l = i, r = n;
		long long mid;
		while(l <= r){
			mid = (l + r) >> 1;
			long long cost = (mid - i) * a[i] - (sum[mid] - sum[i + 1 - 1]);
			if(cost > m){  //¹ýÔ¶ 
				r = mid - 1;
			}else{ //<=
				cnt = max(cnt, mid - i + 1);
				l = mid + 1;
			}
		}
		ans = max(ans, cnt);
	}
	printf("%lld", ans);
	
	return 0;
} 
