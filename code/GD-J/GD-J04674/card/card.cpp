#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 500005,MAXM = 300005;
ll n,m;
ll a[MAXN],b[MAXN];
ll ans[MAXM];
bool t[MAXN];

int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	
	cin >> n >> m;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
		if(t[a[i]] == 0) t[a[i]] = 1;
		else{
			ll tmp = 0;
			for(ll j=i-1;j>=1;j--) if(a[j] == a[i]){tmp = j;break;}
			for(ll j=i-1;j>=tmp;j--) b[j] = tmp;
		}
	}
	
	for(ll i=1;i<=n;i++){
		bool c[MAXN] = {};
		for(ll j=i;j<=n;j++)
			if(b[j] != 0 && b[j] >= i) c[j] = 1;
			
		for(ll j=i;j<=n;j++) if(!c[j]){ans[a[j]]++;c[j] = 1;}
	}
	
	ans[a[n]] = n;
	for(ll i=1;i<=m;i++) cout << ans[i] << ' ';
	return 0;
}
