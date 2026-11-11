#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	int sum = 0 , cnt , d , mark , f = 0 , mark1;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a + 1 , a + n + 1);
	if(n % 2 == 1){
		cnt = a[(n + 1) / 2];
		d = (n + 1) / 2;
	}
	else{
		cnt = a[n / 2 + 1];
		d = n / 2 + 1;
	}
	for(int i = d + 1 ; i <= n ; i++){
		if(cnt == a[i]) f++;
	}
	for(int i = d - 1 ; i >= 1 ; i--){
		mark += (cnt - a[i]);
		if(i == 1 && mark < m){
			mark1 = 0;
			for(int j = d + 1 ; j <= n ; j++){
				mark1 += (a[d + 1] - a[i + 1]);
			}
			if(mark1 == m) {
				cout << d + 1;
			}
			else{
				cout << d;
			}
		}
		else if(mark == m){
			cout << f + d - i + 1;
			break;
		}
	}
	return 0;
} 
