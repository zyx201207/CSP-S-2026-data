#include <bits/stdc++.h>
using namespace std;
long long a[5 * 100000 + 10], cha[5 * 100000 + 10];
bool pd1(int n, int x){
	for(int i = 1; i <= n; i++){
		if(a[i] != x){
			return false;
		}
	}
	return true;
}
bool pd2(int n){
	for(int i = 3; i <= n; i++){
		if(cha[i] != cha[i - 1]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n, m;
	cin >> n >> m;
	cin >> a[1];
	for(int i = 2; i <=n; i++){
		cin >> a[i];
		cha[i] = a[i] - a[i - 1];
	}
	if(pd1(n, a[n])) cout << n << '\n';
	else if(pd2(n)){
		int x = 0;
		for(int i = 1; ; i++){
			x += i;
			if(x > m){
				cout << i << '\n';
				break;
			}else if(x == m){
				cout << i + 1 << '\n';
				break;
			}
		}
	}
} 
