#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;
ll c,t;
ll ans;
ll g[3000086],a[3000086];
void find(ll n,ll d,ll x){
	if(x>n)return;
	a[x]++;
	for(int i=x+1;i<=n;i++){
		if(g[i]-g[x]<=d)find(n,d,i);
		else continue;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		ans=0;
		ll n,d;
		cin>>n>>d;
		if(n<=3||d<1){
			cout<<0<<"\n";
			continue;
		}
		for(ll i=1;i<=n;i++)cin>>g[i];
		
		for(ll i=1;i<=n;i++){
			for(ll z=1;z<=n;z++)a[z]=0;
			find(n,d,i);
			for(ll j=i;j<=n;j++){
				if(a[j]==3)ans++;
			}
		}
		cout<<ans<<"\n";
		
	}
}
