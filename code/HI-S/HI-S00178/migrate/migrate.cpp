#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll N=2e6+10,K=15,INF=0x3f3f3f3f3f3f3f3f;
ll c,t,n,d;
ll a[N],g[K][K];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		if(n==1){
			cout << 0 << endl;
			continue;
		}
		for(int i = 1;i<=n;i++) cin >> a[i];
		ll k=d/(a[2]-a[1]);
		if(k<2){
			cout << 0 << endl;
			continue;
		}
		else{
			cout << max(0ll,n-k-k+1) << endl;
		}
	}
	return 0;
}

