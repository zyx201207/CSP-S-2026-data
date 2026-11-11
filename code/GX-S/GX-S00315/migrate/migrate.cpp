#include<bits/stdc++.h>
using namespace std;
int n,t,c,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.in","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=n-4;
		for(int i=n;i>=n/2;i--){
			if(x[i-1]-x[i-4]>d){
				ans--;
			}
			
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
