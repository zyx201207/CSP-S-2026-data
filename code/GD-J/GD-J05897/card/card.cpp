#include <bits/stdc++.h>
using namespace std;
int a[1000010];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, cnt = 0;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	for(int i=1; i<=n; i++){
		if(a[i] - a[i-1] * 35 + 269 >= 82) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
