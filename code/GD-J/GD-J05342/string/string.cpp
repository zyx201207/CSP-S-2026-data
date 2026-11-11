#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 10;
const ll INF = 1e18;
const int mod = 1e9 + 7;
#define pii pair<int , int>

ll n , a[N];
char c[N];

int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] >> c[i];
	}
	ll ans = 0;
	int l = 1 , r = n;
	while(l < r){
		if(a[l] >= a[r]) {
			if(c[l] != c[r]) ans += a[r];
			a[l] -= a[r] , a[r] = 0;
		}else {
			if(c[l] != c[r]) ans += a[l];
			a[r] -= a[l] , a[l] = 0;
		}
		if(a[l] == 0) l++;
		if(a[r] == 0) r--;
	}
	cout << ans << '\n';
	return 0;
} 

/*
FC /W D:\GD-J05342\string\string.ans D:\GD-J05342\string\string.out


*/
