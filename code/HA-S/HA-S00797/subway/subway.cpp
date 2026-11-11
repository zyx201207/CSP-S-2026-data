#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,be[100010],en[100010],k[505],a[100010][505],t[100010][505],w[500010];
ll ans[i],ned;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++)cin>>a[j][i]>>t[j][i];
	}
	for(ll i=1;i<=q;i++)cin>>be[i]>>en[i];
	for(ll i=1;i<=q;i++)ans[i]=w[be[i]]+w[en[i]],ned=be[i];
    for(ll z=1;z<=q;z++){
		for(ll i=1;i<=n;i++){
    	    for(ll j=1;j<=k[i];j++)if(a[j][i]==ned){if(ned=en[z])break;ans[z]+=t[j][i];ned=a[j][i];}
	    }
    }
	for(ll i=1;i<=q;i++)cout<<ans[i]<<endl;
	return 0;
} 
