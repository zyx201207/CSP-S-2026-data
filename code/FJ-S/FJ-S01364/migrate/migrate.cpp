#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,t,n,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		ll sum=0;
		for(int i=1;i<=n;i++) cin>>x[i],sum+=x[i];
		cout<<abs(sum)<<"\n";
	}
}
