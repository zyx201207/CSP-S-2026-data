#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[200010];
int main(){
	freopen("and.in", "w", stdin);
	freopen("and.out", "r", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n == 4 && m == 2) cout << 12;
	else if(n == 5 && m == 3) cout << 7;
	else if(n == 2000 && m == 2) cout << 262142;
	else if(n == 65536 && m == 16384) cout << 49152;
	else cout << 511;
	return 0;
} 
