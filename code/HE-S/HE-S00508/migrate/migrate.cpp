#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll n,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
		}
	}
	for(ll i=1;i<=n;i++){
		if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
		cout<<"0"<<endl;
		}
	}
for(ll i=1;i<=n;i++){
    	if(x[n]-x[1]<=d){
	    cout<<"0"<<endl;
      }
	}
	return 0;
}
