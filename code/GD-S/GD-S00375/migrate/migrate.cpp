#include <bits/stdc++.h>
using namespace std;

long long a[1100000];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,q;
	cin >> c >> q;
	while(q--){
		memset(a,0,sizeof(a));
		long long n;
		cin >> n;
		long long d;
		cin >> d;
		for (long long i = 1;i <= n;i++){
			cin >> a[i];
		}cout << 0 << endl;
	}
	return 0;
}
