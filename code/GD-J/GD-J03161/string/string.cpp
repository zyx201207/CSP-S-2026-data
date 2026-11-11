#include <bits/stdc++.h>
using namespace std;
char c[200000], b, res_b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n, a[200000];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i] >> c[i];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; i < a[i]; i++){
			b+=c[i];
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = a[i]; i > 0; i--){
			res_b+=c[i];
		}
	}
	if(b == res_b) cout << "0";
	cout << 2;
	return 0;
}
