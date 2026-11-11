#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5,mod=14518964329827;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		string x[10005];
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)cout<<mod%(n*d*(int)x[i][0]/26)<<endl;
	}
	
	
	
	
	
	
	
	return 0;
} 
