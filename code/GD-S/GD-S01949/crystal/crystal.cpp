#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[500010];
ll b[500010];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin >>n>>m;
	for(int i=1; i<=n; i++) {
		cin >>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++) {
		b[i]=(a[i]-a[i-1])*(i-1)+b[i-1];
	}
	ll l=1,r=1;
	ll ans=1;
	while(l<=r) {
		if(r>n)break;
		ans=max(ans,r-l);	
		int k=b[r]-b[l]-a[r]*(l-1)+a[l]*(l-1);
		if(k<=m) {
			r++;
		} else {
			l++;
		}
	}
	cout <<ans;
	return 0;
}

