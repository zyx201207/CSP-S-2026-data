#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll a[N],n,m;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll o,t;
	cin>>o>>t;
	while(t--){
		map<ll,bool> st;
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%lld",a+i);
			st[a[i]]=1;
		}
		sort(a+1,a+n+1);
		if(m<=a[2]-a[1]){
			cout<<"0/n";
			continue;
		}
		ll k=abs(a[2]-a[1]);
		ll f=k*2-1;
		ll ans=n-f+1;
		cout<<ans<<endl;
	}
	return 0;
}
