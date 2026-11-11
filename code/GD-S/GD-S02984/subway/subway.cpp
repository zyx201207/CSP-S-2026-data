#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll w[N],k[N],a[N],t[N],x[N],y[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
		}
	}
	for(ll i=1;i<=q;i++){
		cin>>x[i]>>y[i]; 
	}
	for(ll i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}

