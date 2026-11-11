#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
int c, t, n;
ll d, a[N];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		if (a[2] - a[1] >= d)
			cout << 0 << endl;
	}
	return 0;
}

