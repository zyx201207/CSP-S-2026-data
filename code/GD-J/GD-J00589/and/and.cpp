#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	int maxn = -1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n-1; i++){
		for(int j = i+1; j <= n; j++){
			if(a[i] & a[j] >= maxn){
				maxn = a[i] & a[j];
			}
		}
	}
	cout << maxn;
	return 0;
}
