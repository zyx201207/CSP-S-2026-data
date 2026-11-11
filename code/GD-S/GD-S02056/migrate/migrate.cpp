#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;

const int MAXN = 2114514;


ll c,t;
ll n,d;

ll x[MAXN];

int check(ll x1,ll x2){
	
	if(x[x2] - x[x1] <= d){
		return 1;
	}
	ll nowi = x1;
	ll cnt = 1;
	ll k;
	while(nowi < x2){
		k=0;
		while((x[nowi + k + 1] - x[nowi]) <= d && nowi + k < x2){
			k++; 
		}
		if(k == 0) return 0;
		cnt *= k;
		nowi += k;
	}
	return cnt;
}


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		ll ans = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				ans += (check(j,i) == 2);
				//cout << j << " " << i << " is: "<< check(j,i) << endl;
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}
