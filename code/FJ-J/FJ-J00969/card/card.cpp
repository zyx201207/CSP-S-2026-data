#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int a[N] , b[N];
signed main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n , m;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b+1 , b+1+n);
	int sum = 0 , summ = 0;
	for(int i = 1 ; i <= n ; i++){
		if(a[i] == b[i]) sum++;
		if(a[i] == m) summ++;
	}
	if(sum == n){
		cout << summ;
		return 0;
	}
	if(summ == 0){
		cout << 0;
		return 0;
	}
	return 0;
} 
