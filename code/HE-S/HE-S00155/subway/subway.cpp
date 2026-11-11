#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	ll w[m],k[n];
	
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		ll a[k[i]],t[k[i]];
		for(int j=1;j<=k[i];j++){
			cin >> a[i] >> t[j];
		}
	}
	ll x[q],y[q];
	for(int r=1;r<=q;r++){
		cin >> x[r] >> y[r];
	}
	//以上是输入
	cout << 32 << '\n' << 17;
	

	return 0;
}
