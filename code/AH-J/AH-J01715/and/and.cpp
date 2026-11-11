#include<bits/stdc++.h>
using namespace std;
using ll=long long;
priority_queue<ll,vector<ll>,greater<ll>> pq;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		int x;
		cin>>x;
		pq.push(x);
		if(pq.size()>(long unsigned int)m) pq.pop();
	}
	ll ans=pq.top();
	for(int i=2;i<=m;i++) {
		pq.pop();
		ans&=pq.top();
	}
	cout<<ans;
	return 0;
}
