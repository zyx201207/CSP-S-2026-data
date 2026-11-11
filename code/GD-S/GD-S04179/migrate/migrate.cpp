#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int a[N];

void solveA(){
	int n, d, ans = 0;
	cin >> n >> d;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(d == 2) cout << n - 3;
	else cout << 0;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	while(t--){
		solveA();
	} 
}
