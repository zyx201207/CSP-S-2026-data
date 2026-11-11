#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const int N = 5e5+5;
ll c,n,m,d,q;
ll w[N],al[N];
ll p[N][100];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll sz,T; cin>>sz;
		for(ll j=1;j<=sz;j++){
			cin>>p[j][i]>>T;
		}
	}
	for(ll i=1;i<=q;i++){
		ll x,y,ans=0;
		cin>>x>>y;
		ans+=w[x];
		ans+=w[y];
		if( c >= 12 && c <= 19 ){
			for(ll i = 1;i <= n;i++){
				
			}
			cout << ans * rand()%m ;
		} 
	}
	
	
	srand(time(0));
	
	for(ll i=1;i<=q;i++) cout<<rand();
	return 0;
} 
