//¹À·Ö100 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n , m , a[N] , sum[N] , ans;
#define File(x) freopen(x".in" , "r" , stdin);freopen(x".out" , "w" , stdout)
int Get(int l , int r){
	return sum[r] - sum[l - 1];
}
signed main(){
	File("crystal");	
	scanf("%lld %lld" , &n , &m);
	for(int i = 1;i <= n;i ++){
		scanf("%lld" , a + i);
	}
	sort(a + 1 , a + 1 + n);
	for(int i = 1;i <= n;i ++){
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 1;i <= n;i ++){	
		int l = 1 , r = i , end = 0;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(a[i] * (i - mid + 1) - Get(mid , i) <= m){
				r = mid - 1;	
				end = (i - mid + 1);
			}else{
				l = mid + 1;
			}
		}
		ans = max(ans , end);
	}
	printf("%lld\n" , ans);
	return 0;
}

