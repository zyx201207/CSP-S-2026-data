#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2000005],ans=0;;
ll f[2000005];

ll f2[2000005];
void dfs(ll p,ll d,ll n,ll b){
	b++;
	
	if(b<f2[p])
	{
		if(f[p]==2)
		ans--;
		f[p]=0;
	}
		
	if(b==f2[p]&&f[p]==1)
	ans++;
	if(b==f2[p]&&f[p]==2)
	ans--;
	
	f[p]++;
	f2[p]=b;
	for(ll j=p+1;j<=n;j++){
		if(a[j]-a[p]>d)
		return;
		dfs(j,d,n,b);
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		
			ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i;j<=n;j++)
			f[j]=0;
			dfs(i,d,n,-1);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
