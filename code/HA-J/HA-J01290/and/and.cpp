#include<bits/stdc++.h>
#define ll long long
#define N 100100

using namespace std;

ll n,a[N],m,f[N],maxx;

inline void df(ll x,ll he) {
	if(x==m) {
		maxx=max(he,maxx);
		return ;
	}
	if(he==0) {
		return ;
	}
	for(int i = 1; i <= n; ++i) {
		if(!f[i]) {
			f[i]=1;
			df(x+1,he&a[i]);
			f[i]=0;
		}
	}	
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i) {
		f[i]=1;
		df(1,a[i]);
		f[i]=0;
	}
	cout << maxx << "\n";
 	return 0;
} 
