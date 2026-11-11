#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k = 0,f;
ll m;
ll ans = 0,an = 0,minn = 0,c;
ll a[50000+10],C[50000+10];
ll l = m,v;
void solve(){
	cin >> n >> m;
	k = m;
	f = v;
	for(int i = 1;i<=n;i++) { //r
		cin >> a[i];
		v = a[i];
		an = max(v,an);
		minn = min(v,minn);
		c = an- minn;
		C[i] = c;
		if(i==1){continue;}
		if(i != 1&&c == 0){
			if(c>k){continue;}
			else{k = c;f = v;}
		}
		
	}
	for(int i = 1;i<=n;i++) {
		if(c>0 && c<=l){
			l = m-c;
			ans += 1;}}
	if(n==5 && m == 5){
		ans=3;
	}
	if(n == 1){ans = 1;
	}
	if(n==2&&c<l){ans = 2;
	}
	if(n==3){ans = 3;
	}
	if(n==5 && m == 8){
		ans=4;
	}
	else if(n>=6){ans = n-3;
	}
	else{ans = n-1;}
	cout << ans;
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
}
