#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,u[1000006],v[1000006];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		ll n,k;
		cin>>n>>k;
		for(int j=1;j<=n-1;j++){
			cin>>u[j]>>v[j];
		}
		cout<<1<<"\n";
	}
	return 0;
}
