#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll n , m , a[N] , pre[N] , ans;
//5 5
//1 2 4 8 9
ll ef(int x){
	int l = 1 , r = x-1;
	while(l < r){
		int mid = (l + r) >> 1;
		if(pre[x-1]-pre[mid-1]+m >= a[x]*(x-mid)) r = mid;
		else l = mid + 1;
	}
	if(pre[x-1]-pre[l-1]+m < a[x]*(x-l)) return x;
	return l;
}
int main(){
	
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	
	scanf("%lld%lld" , &n , &m);
	for(int i = 1;i <= n;i++) scanf("%lld" , &a[i]);
	sort(a+1 , a+n+1);
	for(int i = 1;i <= n;i++) pre[i] = pre[i-1] + a[i];
	for(int i = 1;i <= n;i++){
		ll ad = i - ef(i) + 1;
		ans = max(ans , ad);
//		cout << ad << ' ';
	}
	printf("%lld" , ans);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
//5 5
//1 2 4 8 9
