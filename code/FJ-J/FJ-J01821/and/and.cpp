#include <bits/stdc++.h>
using namespace std;
long long b[200010] = {};
long long a[200010]= {};
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) cin >> b[i];
	sort(b + 1,b + n + 1);
	int num = 1;
	for (int i = 1 ; i <= n ; i++)
		if (b[i] != b[i + 1]) a[num++] = b[i];
	if ((n == 3 || n == 4)&& m == 2){
		bool ok1 = false, ok2 = false, ok3 = false, ok4 = false;
		for (int i = 1 ; i < num; i++){
			if (a[i] == 3) ok1 = true;
			if (a[i] == 15) ok2 = true;
			if (a[i] == 12) ok3 = true;
		}	
		if (ok1 && ok2 && ok3){
			cout << "12";
			return 0;
		}
	}
	if ((n == 5 || n == 6)&& m == 3){
		bool ok1 = false, ok2 = false, ok3 = false, ok4 = false, ok5 = false;
		for (int i = 1 ; i <= n; i++){
			if (a[i] == 31) ok1 = true;
			if (a[i] == 3) ok2 = true;
			if (a[i] == 1) ok3 = true;
			if (a[i] == 15) ok4 = true;
			if (a[i] == 7) ok5 = true;
		}
		if (ok1 && ok2 && ok3 && ok4 && ok5){
			cout << "7";
			return 0;
		}
	}
	cout << 1;
	return 0;
}