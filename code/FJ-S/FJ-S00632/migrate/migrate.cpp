#include<bits/stdc++.h>
using namespace std;
int x[2000005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,f=0;
	cin>>c>>t;
	while(t--){
		f=0,ans=0;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int k=x[n]-x[n-1];
		for(int i=1;i<n;i++){
			if(x[i+1]-x[i]!=k)f=1;
		}
		if(f==0){
			for(int i=1;i<n;i++){
				if(x[i]+d+1>x[n]){
					break;
				}else{
					ans++;				
				}
			}
			cout<<ans<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	
	return 0;
}
