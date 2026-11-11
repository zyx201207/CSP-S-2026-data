#include <bits/stdc++.h>
using namespace std;
int a[500010], b[500010];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if(n == 1){
		cout << 1 << endl;
		break;
	}
	for(int i=1; i<=n; i++){
		cin >> a[i];
		for(int j=1; j<i; j++){
			if(a[i] < a[j]) swap(a[i], a[j]);
			else break;
		}
	}
	for(int i=1; i<n; i++){
		b[i] = a[i+1] - a[i];
		if(i >= 2 and b[i] == b[i-1]){
			continue;
		}else{
			flag = false;
		}
	}
	if(flag == true){
		if(b[1] = b[2]){
			cout << n << endl;
		}else{
			cout << n / m << endl;
		}
	}
	return 0;
}
