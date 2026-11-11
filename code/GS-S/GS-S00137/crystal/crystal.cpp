#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],t;
void solve(){
	for(int k=1;k<=n;k++){
		ll mid = a[k];
		if(a[k]!=a[k-1] || k==1){
			ll ans = m,cnt = 0;
			for(int i=k;i<=n;i++){
				int x = mid - a[i];
				if(ans>=x){
					ans -= x;
					cnt++;
				}
				else break;
			}
			t = max(t,cnt);
		}
	}
}
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	solve();
	cout<<t;
	return 0;
}
