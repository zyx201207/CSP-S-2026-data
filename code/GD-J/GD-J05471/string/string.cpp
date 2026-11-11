#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2e5+5;

ll n, ans;

struct node{
	ll x;
	char c;
}a[maxn];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].x >> a[i].c;
	} 
	
	ll l = 1, r = n, cnt = 0;
	
	for(; l < r; l++){
		while(cnt < a[l].x) {
			if(a[r].c != a[l].c) ans += a[r].x;
			cnt += a[r--].x;
		}
		a[++r].x = cnt - a[l].x;
		cnt = 0;
		if(a[r].c != a[l].c) ans -= a[r].x;
//		cout << ans << " " << cnt << "\n";
	}
	cout << ans;
	
	return 0;
}



/*
      _|          _|_|_|
     _|_|       _|      _|
    _|  _|     _|        
   _|    _|    _|       
  _|_|_|_|_|   _|        _|
 _|        _|   _|      _|
_|          _|    _|_|_|
*/
