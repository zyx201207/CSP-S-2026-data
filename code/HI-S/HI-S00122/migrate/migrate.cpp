#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 6;
int x[N];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin>>c>>t;
	while(t--){
		int n, d;
		cin>>n>>d;
		
		for(int i=1; i<=n; i++)cin>>x[i];
		
		if(n==2){
			cout<<0<<'\n';
			continue;
		}
		
		int ans=0;
		int c=x[2]-x[1];
		if(d>=2*c)ans+=(n-2);
		cout<<ans<<'\n';
	}
	
	return 0;
}
