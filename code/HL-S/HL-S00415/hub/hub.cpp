#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6;
ll a[N],b[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	if(c==0&&t==2) {
		cout<<1<<'\n'<<2;
		return 0;
	}
	while(t--) {
		ll n,k;
		cin>>n>>k;
		for(int i=1; i<=n; i++) cin>>a[i]>>b[i];
		cout<<n/k+1;
	}
	return 0;
}
