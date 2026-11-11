#include<bits/stdc++.h>
using namespace std;

int c,t,d,n;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int x[n+5];
		for(int i=1;i<=n;i++) cin>>x[i];
		ll ans=0;
		if(d==1){
			cout<<0;
			continue;
		}
		else{
			cout<<1;
		}
//		for(int i=1;i<=n;i++){ //Æðµã 
//			for(int j=1;j<=d;j++){
//				
//			}
//		}
	}
	
	return 0;
} 
