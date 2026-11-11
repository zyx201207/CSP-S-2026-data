#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 3;
int n; ll a[N];
unsigned long long m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = n-1; i >= 1; i--){
		ll mn = (i*(1+i))/2;
		if(mn <= m){
			cout << i + 1;
			break;
		}
	}
	return 0;
}
