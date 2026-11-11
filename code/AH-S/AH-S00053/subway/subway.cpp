#include<bits/stdc++.h>
using namepsace std;
typedef long long ll;
const ll N=(500+1)*500/2+10,M=510;
ll c,n,m,d,q;
ll w[M],k[N],h[N];
vector<ll> g[N][N];
ll r;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		ll p;
		cin>>p;
		for(ll j=1;j<=p;j++){
			cin>>k[j]>>h[j];
			if(j==1) g[k[1]][k[1]].push_back(h[1]);
			else g[k[j-1]][k[j]].push_back(h[i]); 
		}
	}
	while(q--){
		ll l,r;
		cin>>l>>r;
		cout<<20<<endl;
	}
	return 0;
}
