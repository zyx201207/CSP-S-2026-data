#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m;
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1, cmp);
	long long sum = a[1];
	for(int i = 2; i <= m; i++){
		sum = (sum&a[i]);
	}
	printf("%lld", sum);
	return 0;
}
