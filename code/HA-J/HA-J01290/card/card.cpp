#include<bits/stdc++.h>
#define ll long long
#define N 100100

using namespace std;

ll n,a[N],he,m,f[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n; ++j) {
			ll x=lower_bound(a,a+n+1,a[i])-a;
			for(int y=i;y<=x;++y) {
				f[y]=1;
			}			
		}
		for(int j = i; j <= n; ++j) {
			
		}
	}
	cout << he << "\n";
	return 0;
}
