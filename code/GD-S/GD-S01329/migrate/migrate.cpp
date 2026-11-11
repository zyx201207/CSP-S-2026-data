#include<bits/stdc++.h>
#include<cstdio>
typedef long long ll;
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;cin>>c>>t;ll n,d;
	while(t--){
		ll a[2000005];
		cin>>n>>d;ll cha;bool canA=true;
		for(int i=1;i<=n;i++){
		cin>>a[i];if(i==2)cha=a[2]-a[1];
		if(cha!=a[i]-a[i-1]&&i!=1)canA=false;
		}
		if(canA){
			if(d>=cha)cout<<n<<'\n';
			else cout<<0<<'\n';
		}
	
	}
	
	return 0;
} 
