
#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 1e5+10;
int n, m;
int a[N], b[N], c[N];

int end(int x){
	for(int i = 1; i <= n; i++){
		int t;
		t = b[i];
		if()
	}
}

int main(){
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		c[i] = a[i];
		while(c[i] != 0){
			b[i] += c[i] % 2;
			b[i] *= 10;
			c[i] /= 2;
		}
		b[i] /= 10;
	}
	/*
	for(int i = 1; i <= n; i++){
		cout <<b[i] << " ";
	}

	*/
	int ma = INT_MIN;
	for(int i = 1; i <= n; i++){
		ma = max(ma, a[i]);
	}
	
	cout <<ma;
	return 0;
}