#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		ll n;
		cin>>n;
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	return 0;
}
