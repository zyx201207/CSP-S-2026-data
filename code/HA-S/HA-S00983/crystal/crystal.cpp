#include<bits/stdc++.h>
#define ll long long
#define N 200100

using namespace std;

ll n,a[N],m,b[N],maxx,fl,fll;

inline void f(ll x,ll he,ll sum,ll i) {
	if(he+b[x]*(x-1)>m||x>n) {
		maxx=max(maxx,sum);
		return ;
	}
	f(x+1,he+b[x]*(x-i),sum+1,i);
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	ll cc;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(a[i]!=i) {
			fl=1;
		}
		if(i==2) {
			cc=a[i]-a[i-1];
		}
		if(i>2&&(a[i]-a[i-1])!=cc) {
			fll=1;
		}
	}
	if(!fl) {
		for(int i = 2; i <= n; ++i) {
			if((i-1)*i>m*2) {
				cout << i-1 << "\n";
				return 0;
			}
		}		
		cout << n << "\n";
		return 0;
	}
	if(!fll) {
		for(int i = 2; i <= n; ++i) {
			if((a[i]-a[1])*i>m*2) {
				cout << i-1 << "\n";
				return 0;
			}
		}		
		cout << n << "\n";
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i = 2; i <= n; ++i) {
		b[i]=a[i]-a[i-1];
	}
	for(int i = 1; i <= n; ++i) {
		f(i+1,0,1,i);		
	}
	cout << maxx << "\n";
	return 0;
} 
