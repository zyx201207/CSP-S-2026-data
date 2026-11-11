#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5005;
ll a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	//数学问题，数学问题！
	while(t--){
		ll n, d, ans=0;
		cin >> n >> d;
		for(int i=1; i<=n; ++i){
			cin >> a[i];
		}
		for(int i=1; i<=n; ++i){
			for(int j=i+1; j<=n; ++j){
				if(a[j]-a[i]==2*d-1) ans++;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
