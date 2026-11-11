#include<bits/stdc++.h>
using namespace std;
#define File(x) freopen(x".in" , "r" , stdin);freopen(x".out" , "w" , stdout)
#define int long long
const int N = 2e5 + 5;
int a[N] , n , ans;
char s[N];
//橙 
signed main(){
	File("string"); 
	scanf("%lld" , &n);
	for(int i = 1;i <= n;i ++){
		scanf("%lld%*c%c" , a + i , s + i);
	}
	int l = 1 , r = n;
	while(l < r){//到同一个位置就不用在意了 
		int minn = min(a[l] , a[r]);
//		printf("%lld %lld %c %c %lld %lld %lld\n" , l , r , s[l] , s[r] , a[l] , a[r] , min(a[l] , a[r]));
		ans += (s[l] != s[r]) * minn;
		a[l] -= minn;
		a[r] -= minn;
		if(a[l] == 0){
			l ++;
		}
		if(a[r] == 0){
			r --;
		}
	}
	printf("%lld\n" , ans);
	return 0;
}
//100
