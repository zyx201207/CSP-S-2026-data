#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}


int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n] = {};
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	
	//sort(a.begin(), a.end(), cmp);
	
	int res = a[0];
	if (m==n){
		for (int i=1; i<n; i++){
			res = res & a[i];
		}
	}
	cout << res;
	
	
	return 0;
}