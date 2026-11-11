#include<bits/stdc++.h>
using namespace std;
int c;
long long t,n,d,a[2000001],k[2000001],h;
void solve(){
	long long nm=d/h;
	if(nm<=1){
		cout<<0<<endl;
	}
	else{
		long long nmm=n-2;
		cout<<max(0ll,nmm)<<endl;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<n;i++){
			k[i]=a[i+1]-a[i];
			h=k[i];
		}
			solve();	
		for(int i=1;i<=n;i++)a[i]=0;
		for(int i=1;i<n;i++)k[i]=0;	
		mp.clear();	
		h=0;
	}
	return 0; 
} 
