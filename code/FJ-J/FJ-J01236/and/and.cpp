#include <bits/stdc++.h>
using namespace std;

int a[10000005];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int maxn = -1;
	for (int i = 1; i <= n; i++){
		for (int j = 2; j <= i; j++){
			if (a[i] and a[j] > maxn){
				maxn = a[i] and a[j];
			}
		}
	}
	cout << maxn << endl;
}
