#include <bits/stdc++.h>
#define int long long
using namespace std;
int n , m;
const int maxn = 3e5 + 10;
int a[maxn];
bool check(int d){
	int cnt = 0;
//	cout << d << '\n';
	for(int i = 1 ; i <= n ; i++){
//		if(d == 7) cout << (d & a[i]) << ' ';
		if((d & a[i]) == d) ++cnt;
	}
//	cout << endl;
	return cnt >= m;
}
signed main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int max1 = 0;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		max1 = max(a[i] , max1);
	}
	if(m == n){
		int yu = a[1];
		for(int i = 2 ; i <= n ; i++){
			yu &= a[i];
		} 
		cout << yu;
	}
	else if(m == 1){
		cout << max1;
	}
	else if(n <= 2000 && m == 2){
		int yu = 0;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				if(i == j) continue;
				yu = max(a[i] & a[j] , yu);
			}
		}
		cout << yu;
	}
	else{
		int gg = 0;
		for(int i = max1 ; i >= 0 ; i--){
			if(check(i)){
				gg = i;
				break;
			}
		}
		cout << gg;
	}
	
	return 0;
}
/*
5 3
31 3 1 15 7
*/
