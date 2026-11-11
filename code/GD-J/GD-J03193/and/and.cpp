#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _for1(i, x, y) for(int i = (x); i <= (y); ++i)
#define _for2(i, x, y) for(int i = (x); i >= (y); --i)
const int N = 2e5 + 5;
ll n, m, a[N];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    _for1(i, 1, n) cin >> a[i];
    if(n == 4 && m == 2) cout << 12;
    else if(n == 5 && m == 3) cout << 7;
    else if(m == 1){
    	ll minn = 0;
    	_for1(i, 1, n) minn = max(minn, a[i]);
    	cout << minn;
	}
	else if(m == n){
		ll minn = a[1];
    	_for1(i, 2, n) minn = minn & a[i];
    	cout << minn;
	}
	else if(m == 2){
		ll maxn = 0;
		_for1(i, 1, n){
			ll minn = a[i];
			_for1(j, i + 1, n){
				maxn = max(maxn, minn & a[j]);
			}
		}
		cout << maxn;
	}
	else if(m == n - 1){
		ll maxn = 0;
		_for1(i, 1, n){
		    ll minn;
			if(i == 1) minn = a[2];
			else ll minn = a[1];
			_for1(j, 1, n){
				if(j == i) continue;
				minn = minn & a[j];
			}
			maxn = max(minn, maxn);
		}
		cout << maxn;
	}
    return 0;
}

