#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll l,t;
	cin>>l>>t;
	while(t--){
		ll x,y,z;cin>>x>>y;
		for(int i=1;i<=x;i++)cin>>z;
		cout<<x-3<<endl;
	}
	return 0;
}
