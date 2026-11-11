#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,ans=1000000000,sta[500005];
struct sub{
	ll bgn;
	ll bt;
	ll end;
	ll et;
	ll k;
}a[1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>sta[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>a[i].k; 
		if(a[i].k==1){
			cin>>a[i].bgn>>a[i].bt;
		}
		else {
			cin>>a[i].bgn>>a[i].bt>>a[i].end>>a[i].et;
		}		
	}
	for(ll v=1;v<=q;v++){
		ll x;
		ll y;
		cin>>x>>y;
		for(ll i=1;i<=n;i++){
			ll sum=0;
			if(a[i].bgn!=x||a[i].k==1)
			continue;
			sum+=sta[x]+a[i].bt;
			if(a[i].end==y){
				sum+=a[i].et+sta[y];
				ans=min(ans,sum);
			}
     else{
     	for(ll j=1;j<=n;j++){
     		if(a[j].bgn!=a[i].end)
			continue;
			if(a[j].end==y){
				sum+=a[j].et+sta[y];
				ans=min(ans,sum);
			}
		 }
	 }
	}
	cout<<ans;
	ans=1000000000;
}
	return 0;
}
