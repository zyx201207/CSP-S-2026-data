#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int N = 500005; 
int n, m, l, r, mid, ans;
int a[N];
bool ok(int x){
	int num;
	for(int i=1; i<=n-x+1; i++){
		num = 0;
		int end = i + x - 1;
		for(int j=i; j<end; j++){
			num+=(a[end]-a[j]);
			if(num > m){
				break;
			}
		}
		if(num <= m){
			return 1;
		} 
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	l = 1;
	r = n + 1;
	while(l < r){
		mid = (l + r) / 2;
		if(ok(mid)){
			ans = mid;
			l = mid + 1;
		}else{
			r = mid;
		}
	}
	if(ans == 1){
		printf("0");
	}else{
		printf("%lld", ans);
	}
	return 0;
}
