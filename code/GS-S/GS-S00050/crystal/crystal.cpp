#include<bits/stdc++.h>
using namespace std;
#define itn int
long long n,m,a[500010];
itn main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	long long x = a[2] - a[1],c = 0;
	for(int i = 1;i <= n;i++){
		if((m - i * x) >= 0){
			m -= i * x;
			c++;
		}
	}
	cout << c;
	return 0;
}
