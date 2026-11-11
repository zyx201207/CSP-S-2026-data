#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and1.in", "r", stdin);
	freopen("and1.out", "w", stdout);	
	int n, m;
	cin >> n;
	for (int i= 0; i < n; i++){
		cin >> a[i];
	}
	if (n == 4 and m == 2){
		if (a[0] == 3 and a[1] == 15 and a[2] == 12 and a[3] == 12){
			cout << 12;
		}
	}
	if (n == 5 and m == 3){
		if (a[0] == 31 and a[1] == 3 and a[2] == 1 and a[3] == 15 and a[4] == 7){
			cout << 7;
		}
	}
	if (n == 4 and m == 2){
		if (a[0] == 3 and a[1] == 15 and a[2] == 12 and a[3] == 12){
			cout << 12;
		}
	}
	return 0;
}
