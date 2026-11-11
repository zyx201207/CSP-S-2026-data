#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		int n;ll d;cin>>n>>d;
		vector<ll>a(n+1);
		ll ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n-2;i++){
			for(int j=i+2;j<=n;j++){
				ll sum=0;
				for(int k=i+1;k<j;k++){
					if(a[k]-a[i]<=d&&a[j]-a[k]<=d)sum++;
				}
				if(sum==2)ans++;
			} 
		}
		cout<<ans<<'\n';
	}
	return 0;
}
