#include<bits/stdc++.h>
using namespace std;
int t,m,b,c;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n-1;i++){
			ans+=i-1;
		}cout<<ans<<"\n";
	}
	
	return 0;
}
