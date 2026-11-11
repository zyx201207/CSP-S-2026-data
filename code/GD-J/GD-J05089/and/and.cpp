#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n = 0, m = 0;
	cin >> n >> m;
	long long a[200001] = {0};
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort (a+1, a+n+1, cmp);
	
	int ans = a[1];
	for (int i=2; i<=m; i++){
		ans &= a[i];
	}
	
	cout << ans;
	
	return 0;
}
