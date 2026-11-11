#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[500010],m1[300010],ans[300010];
queue<ll>q;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(ll i=1; i<=n; i++) {
		for(ll j=i; j<=n; j++) {
			if(m[a[i]]!=0) {
				while(q.empty()) {
					q.pop();
				}
			}
			q.push(a[i]);
			m[a[i]]++;
		}
		while(!q.empty()){
			ll u=q.front();q.pop();
			ans[u]++;
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
