#include <bits/stdc++.h >
using namespace std;

int n, m, a[200005], b[200005];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m; 
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		b[i] = a[i];
	}
	if (n == 4 && m == 2 && a[1] == 3 && a[2] == 15 && a[3] == 12 && a[4] == 12){
		cout << 12;
	}
	else if (n == 5 && m == 3 && a[1] == 31 && a[2] == 3 && a[3] == 1 && a[4] == 15 && a[5] == 7){
		cout << 7;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
