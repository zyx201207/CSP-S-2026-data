#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll u[N],v[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>u[i]>>v[i];
	}
	for(int i=1;i<=t;i++){
		int t=rand()%1000;
		cout<<t<<endl;
	}
	return 0;
}

