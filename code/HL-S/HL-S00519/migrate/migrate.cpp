#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6;
signed main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		int x[N];
		if(n<3){
		 	cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(x[2]-x[1]>d){
			cout<<0<<endl;
			continue;
		}
	}
	return 0;
}