#include<bits/stdc++.h>
using namespace std;
int n , m;
int a[200005];
//15
int main( ){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) scanf("%d" , &a[i]);
	if(m == 1){
		sort(a + 1 , a + n + 1);
		cout << a[n];
		return 0;
	}
	if(m == n){
		long long ans = a[1];
		for(int i = 2;i <= n;i ++){
			ans = (ans & a[i]);
		}
		cout << ans;
		return 0;
	}
	sort(a + 1 ,a + n + 1);
	cout << a[n - m];
	return 0;
}
