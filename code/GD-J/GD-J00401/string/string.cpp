#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[200005],b = 0;
	char c[200005];
	cin >> n;
	for (int i = 0;i < n;i++){
		cin >> a[i] >> c[i];
		if (c[i] != 'a'){
			b += a[i];
		}
	}
	cout << b;
	return 0;
}
