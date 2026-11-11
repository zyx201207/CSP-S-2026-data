#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
struct node{
	ll k,a[20005],t[20005];
}xl[505];
ll c,n,m,d,q,w[500005];
vector<ll> vec[2005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>xl[i].k;
		for(ll j=1;j<=xl[i].k;j++){
			cin>>xl[i].a[j]>>xl[i].t[j];
			vec[xl[i].a[j]].push_back(i);
		}
	}
	for(ll i=1;i<=q;i++){
		ll x,y;
		cin>>x>>y;
		cout<<xl[vec[x][0]].t[1]*2+w[x]+w[y]<<"\n";
	}
	return 0;
}
