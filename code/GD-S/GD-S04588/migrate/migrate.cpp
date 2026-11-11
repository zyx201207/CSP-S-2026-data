#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 5;
int a[N];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int c,t,n,d;
	cin >> c >> t;
	while(t --){
		cin >> n >> d;
		if(n == 1){
			cout << "0\n";
			continue;
		} 
		for(int i = 1;i <= n;i ++){
			scanf("%lld",&a[i]);
		}
		int cf = a[2] - a[1];
		int ln = d / cf;
		if(ln <= 1){
			cout << "0\n";
			continue;
		}
		cout << max(0LL,n - 2 * ln + 1) << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
0 1
10 21
0 7 14 21 28 35 42 49 56 63
*/
