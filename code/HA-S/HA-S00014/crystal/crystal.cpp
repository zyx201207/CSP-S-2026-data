#include <bits/stdc++.h>
using namespace std;
long long n,m,a[700000],f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> a[1];
	int sum = 0;
	for(int i = 2;i <= n;i++){
		cin >> a[i];
		sum += (a[i] - a[i - 1]) * (i - 1);
		if(sum >= m && !f){
			f = 1;
			if(sum == m) cout << i;
			else cout << i - 1;
		}
	}
	if(!f) cout << n;
	return 0;
}
