#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[2000005],k,l,r,vis,t,f1,f2;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=2;i<n;i++){
			if(a[i+1]-a[i]!=a[i]-a[i-1])vis=1;
		}
		if(!vis){
			if(d<a[3]-a[1]||d>=a[n]-a[1]){
			cout<<"0"<<endl;
			continue;
		}
		int x=d/(a[2]-a[1]);
		for(int i=1;i<d;i++){
			ans+=(n-d-i);
		}
		cout<<ans<<endl;
		}	
		else{
			long long f1=a[1]+d,f2=a[n]-d;
			for(int i=1;i<=n;i++){
				if(a[i]>=f2){
					f2=i;
					break;
				}
			}
			for(int i=n;i>=1;i--){
				if(a[i]<=f1){
					f1=i;
					break;
				}
			}
			if((f1-f2)==1)cout<<"1"<<endl;
			else cout<<"0"<<endl;
		}	
		
	return 0;
}
}
/*
*/
