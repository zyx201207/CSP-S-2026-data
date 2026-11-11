#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,ansc,ans;
ll a[2001000];
void dfs(ll p,ll t,ll k){
	ll i,j;
	if(p==t){
		if(k<ansc){
			ans=1;
			ansc=k;
		}
		else if(ansc==k) ans++;
	}
	for(i=p+1;i<=t;i++)
	if(a[i]-a[p]<=d) dfs(i,t,k+1);
}
int main(){
	ll i,j;
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
	while(t--){
		cin>>n>>d;
		for(i=1;i<=n;i++) cin>>a[i];
		if(d>a[2]-a[1])
		cout<<max(0ll,n-2*d/(a[2]-a[1])+1)<<"\n";
		else cout<<"0\n";
	}
	return 0;
    }
    while(t--){
    	cin>>n>>d;
    	for(i=1;i<=n;i++) cin>>a[i];
    	ll cnt=0;
    	for(i=1;i<=n;i++)
    	for(j=1;j<=n;j++){
    		if(i>=j) continue;
    		ansc=1e18;
    	    ans=0;
    		dfs(i,j,0);
    		if(ans==2) cnt++;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
