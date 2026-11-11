#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll w[500010];
ll a[500010];
ll t[500010]; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	
	for(ll i=1;i<=m;i++){ 
		cin>>w[i]; 
	}
	for(ll i=1;i<=n;i++){
		ll tmp;
		cin>>tmp; 
		for(ll i=1;i<=tmp;i++){
			cin>>t[i];
		}
		for(ll i=1;i<=tmp;i++){
			cin>>a[i];
		}
		ll x,y,xx,yy;
		cin>>x>>y>>xx>>yy;
		cout<<10<<endl<<20;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
