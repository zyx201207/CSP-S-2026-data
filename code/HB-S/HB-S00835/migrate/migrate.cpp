#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[2000005];
int main(){
	freopen("migrate.in","r" , stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i = 1;i <= t;i ++){
		cin >> n >> d;
		int cha;
		for(int j = 1;j <= n;j ++)
			cin >> a[j];
		cha = a[n] - a[n-1];
		if(cha*2 > d)cout << 0 << endl;
		else cout << n - 3;
	}
	return 0;
}
