#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll c,t,i=0;
	cin>>c>>t;
	while(t--){
		i++;
		ll n,k;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)cin>>k>>k;
		cout<<i<<endl;
	}
	return 0;
}

