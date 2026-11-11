#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[505505],t[303303];
queue <ll> q;
queue <ll> p;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1; i<=n; i++) {
		ll x;
		cin>>x;
		a[i]=x;
		p.push(x);
	}
	ll i=1;
	while(i<=n) {
		for(ll j=1; j<=q.size(); j++) {
			p.push(a[i]);
		}
		for(ll j=1; j<=i; j++) {
			if(a[i]==a[j]) {
				for(ll k=1; k<j; k++) {
					p.pop();
				}
			}
		}

		for(ll j=1; j<=p.size(); j++) {
			t[p.front()]++;
			p.pop();
		}
		for(ll j=1; j<m; j++) {
			cout<<t[j]<<" ";
		}
		i++;
	}
	return 0;
}
/*
1 2 1 3
 1  2 3
 2  1 1
1 3 2 4
*/
