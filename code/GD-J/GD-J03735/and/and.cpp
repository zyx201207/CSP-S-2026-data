#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++) cin >> a[i];
	if(m==1) cout << *max_element(a.begin()+1,a.end()) << '\n';
	else if(m==n){
		ll ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout << ans << '\n';
	}else if(m==2 && n<=20000){
		ll mx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}cout << mx << '\n';
	}else{
		sort(a.begin()+1,a.end(),greater<>());
		ll ans=a[1];
		for(int i=2;i<=m;i++){
			ans&=a[i];
		}cout << ans << '\n';
	}
	return 0;
}
