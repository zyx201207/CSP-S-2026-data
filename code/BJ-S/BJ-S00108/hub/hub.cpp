#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,q;
	cin>>c>>q;
	while(q--){
		cin>>n>>m;
		ll x,y,mn;
		while(n--){
			cin>>x>>y;
			mn=min(min(x,y),mn);
		}
		cout<<max(mn,0ll)<<"\n";
	}
	return 0;
}
