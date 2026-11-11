#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,a;
	cin>>c>>t;
	while(t--){
		int n,d,a,b,l;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a;
			if(i==1) b=a;
			if(i==2) l=a-b;
		}
			if(l>d) cout<<0<<"\n"; 
			else{
				int ans=0;
				for(int i=1;i<n;i++){
					ans+=i;
				}
				cout<<ans<<"\n";
			}
	}
	return 0;
}

