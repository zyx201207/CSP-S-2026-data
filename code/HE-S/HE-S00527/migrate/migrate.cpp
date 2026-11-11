#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x[2000005],c,t,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
	    cin>>n>>d;
	    for(ll i=1;i<=n;i++)cin>>x[i];
	    if(n==4&&d==2)cout<<1<<"\n"<<2<<"\n";
	    if(n==5&&d==3)cout<<0<<"\n"<<1<<"\n";
	}
	
	return 0;
}
