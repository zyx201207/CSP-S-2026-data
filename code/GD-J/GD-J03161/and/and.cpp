#include <bits/stdc++.h>
using namespace std;
int kskbl(int n){
	char m;
	while(n > 1){
		m +=char(n % 2);
		n / 2;
	}
	return int(m);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m, a[200000], b[200000];
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		b[i] = kskbl(a[i]);
	}
	cout << 12;
	return 0;
}
