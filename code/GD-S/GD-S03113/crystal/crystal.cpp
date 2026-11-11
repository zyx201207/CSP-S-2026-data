#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],b[500005],c[500005],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b[1]=a[1];
	for(ll i=2;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	priority_queue<ll> pq;
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			ll x;
			x=a[j]*(j-i+1)-(b[j]-b[i-1]);
			if(x<=m)pq.push(j-i+1);
		}
	}
	if(pq.empty())cout<<1;
	else cout<<pq.top();
	return 0;
} 
