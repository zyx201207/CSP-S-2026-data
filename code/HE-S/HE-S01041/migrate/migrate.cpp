#include <bits/stdc++.h>
using namespace std;
int main (){
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
		long long c,t;
	cin >> c >> t;
	while (t--){
		long long n,d;
		cin >> n >> d;
		long long x[n];
		for(long long i = 0;i < n;i++) cin >> x[i];
		long long m[n + 1] = {};
		for(long long i = 1;i <= d;i++)
			for(long long j = 1;j <= d;j++) m[i + j]++;
		long long cnt = 0;
		for(long long i = 0;i <= n;i++)
			if(m[i] == 2) cnt++;
		cout << cnt << endl;
	}
	return 0;
	return 0;
}
