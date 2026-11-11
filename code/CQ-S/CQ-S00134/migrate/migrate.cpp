#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
void fast(){
	 ios::sync_with_stdio(0);
	 cin.tie(0),cout.tie(0);
	 return ;
}
ll a[N];
signed main(){
	   fast();
	   freopen("migrate.in","r",stdin);
	  freopen("migrate.out","w",stdout);
	   ll c,t;
	   cin>>c>>t;
	   while(t--){
	   	ll n,d,ans=0;
	   	cin>>n>>d;
	   	for(int i=1;i<=n;i++){
	   		cin>>a[i];
		   }
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[j]-a[i])%d!=0&&abs(a[j]-a[i])>(d-1)&&a[j]+a[i]!=(a[n]+a[1])*n/2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	   }
	   return 0;
}

