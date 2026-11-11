#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;

int n , num[N] , m , ans[N];

int check(int x , int y){
	int sum = ans[x] , one = 2;
	for (int i = x + 1 ; i <= y ; i++){
		sum += ans[i] * one;
		one++;
	}
//	cout << x << " " << y << " " << sum << "\n";
	return sum;
}

signed main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++){
		cin >> num[i];
		ans[i] = num[i] - num[i - 1];

	}
	int fin = 1;
	ans[1] = 0;
	for (int i = 2 ; i <= n ; i++){
		for (int j = i ; j <= n ; j++){
//			cout << fin << "    " << i << " " << j << " " << check(i , j) << "\n";
			if (check(i , j) <= m) fin = max(fin , j - i + 2);
			else break; 
		}
	}
	cout << fin;
	
	return 0;
} 
