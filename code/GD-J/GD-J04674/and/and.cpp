#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 200005;
ll n,m;
ll a[MAXN];
bool b[MAXN];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	
	cin >> n >> m;
	for(ll i=1;i<=n;i++) cin >> a[i];
	
	ll ans = 0;
	for(ll i=1;i<=m;i++){
		ll maxn = 0,maxm = 0;
		for(ll j=1;j<=n;j++)
			if(!b[j] && a[j] > maxn){maxn = a[j];maxm = j;}
		
		b[maxm] = 1;
		if(i == 1) ans = maxn;
		else ans &= maxn;
	}
	cout << ans;
	return 0;
} 
