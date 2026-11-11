#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 2<<60
ll c,t,n,d,x[2000002];
ll ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("t.txt","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
//		for(int i=1;i<=n;i++)x[i]=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		//if(c==11||c==12){
			ll k=x[2]-x[1];
			//cout<<n<<' '<<k<<' '<<d<<' ';
			if(k>=d){
				cout<<0<<'\n';
			}
			else{
				ll r=d/k;ans=n-2*r+1;
				if(ans>0)cout<<ans<<'\n';
				else cout<<0<<'\n';
			}
			
		//}
	}
	
	return 0;
} 
