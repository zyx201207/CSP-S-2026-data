#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=500050;
ll c,n,m,d,q;
ll w[N];
ll sum;
void solve(){
	cin >> c >> n >> m >> d >> q;
	for(ll i=0;i<m;i++)cin >> w[i];
	for(ll i=0;i<n;i++){
		ll temp;
		cin >> temp;
		sum+=temp;
	}
	cout << sum;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve();
	return 0;
}
