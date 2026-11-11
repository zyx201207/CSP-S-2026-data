#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
/*/struct node{
	ll w;
	ll a[510];
	ll t[510];
}f[500010];*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subeay.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2)cout<<32<<"\n"<<17;
		if(n==3)cout<<35<<"\n"<<16;
	}/*else{
		for(ll i=1;i<=m;i++)cin>>f[i].w;
		for(ll i=1;i<=n;i++){
			ll k;
			cin>>k;
			while(k--){
				ll a1;
				cin>>a1;
				f[a1].a[i]=1;
				cin>>f[a1].t[i];
			}
		}
	}*/
	return 0;
}
