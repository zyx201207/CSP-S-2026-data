#include <bits/stdc++.h>
using namespace std;
using ll= long long;
ll c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		vector<ll>s(n);
		for(int i=0;i<n;i++){
			cin>>s[i];
		} 
		if(d==n-1){
			cout<<0<<endl;
		}else if(d==1){
			cout<<0<<endl;
		}else{
			if((n/d-1)>=0)
				cout<<n/d-1<<endl;
			else
				cout<<n/d<<endl;
		}
	}
	return 0;
}
