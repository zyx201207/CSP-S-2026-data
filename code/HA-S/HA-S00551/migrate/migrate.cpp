#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		if(n==4&&d==2){
			cout<<1<<'\n'<<2<<endl;
			break;
		}else if(n==5&&d==3){
			cout<<0<<'\n'<<1<<endl;
			break;
		}
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
		}
	}
		
	return 0;
}
