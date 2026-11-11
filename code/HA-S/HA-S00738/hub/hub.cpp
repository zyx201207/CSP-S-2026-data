#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	for(int i=1; i<=t; i++) {
		ll n,m;
		cin>>n>>m;
		for(int i=1; i<=n-1; i++) {
			cin>>a[i]>>a[i];
		}
		cout<<n/2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

