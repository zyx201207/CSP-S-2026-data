#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
bool cmp(ll a,ll b){
	return a < b;
}
ll n,m,n1[200005]; 
void solve(){
	cin >> n >> m;
	for(ll i = 1;i <= n;i++){
		cin >> n1[i];
	}
	if(m==1){
		sort(n1+1,n1+n+1,cmp);
		cout << n1[1];
	}if(m==2){
		ll ans = 0;
		for(ll i = 1;i <= n;i++){
			for(ll j = 1;j <= n;j++){
				ans = max(ans,ll(n1[i] & n1[j]));
			}
		}cout << ans;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

