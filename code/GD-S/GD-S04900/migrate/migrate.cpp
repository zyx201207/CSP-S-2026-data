#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		vector<ll>x(n+1);
		bool pA=true,pB=false;
		for(int i=1;i<=n;i++) {
			cin>>x[i];
			if(i>1 && !(x[i]-x[i-1]==x[2]-x[1])) pA=false;
		}
		ll mx=INT_MAX;
		for(int i=1;i<=n;i++){
			mx=min(mx,max(x[i]-x[1],x[n]-x[i]));
		}
		if(mx<=d) pB=true;
		if(pA || pB){
			cout<<0<<endl;
		}
		else cout<<1<<endl;
	}
	
	return 0;
}

