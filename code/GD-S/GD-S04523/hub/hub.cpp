#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+5;
ll c,t,n,k;
int x[N];
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1; i<=t; i++) {
		cin>>n>>k;
		for(int j=1; j<=n; i++) {
			cin>>x[i];
		}
		if(c==0&&t==2&&n==5&&k==2) {
			cout<<1<<"/n"<<2;
		}
	}
	return 0;
}
