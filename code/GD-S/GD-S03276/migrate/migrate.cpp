#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,d,a[2000009];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		if(a[n]-a[1]>=d){
			ll x=1,y=n-3;
			cout<<(x+y)*y/2<<"\n";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
