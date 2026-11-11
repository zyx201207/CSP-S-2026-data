#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		bool f=1;
		for(int i=1;i<n;i++) if(x[i]+1!=x[i+1]) f=0;
		if(f==1){
			cout<<n-2*d+1<<"\n";
			continue;
		}
		if(x[n]-x[1]<=d){
			cout<<0<<"\n";
			continue;
		}
	}
	return 0;
}
