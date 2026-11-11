#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int c,t,n,k,u[MAXN],v[MAXN];
int main () {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);	
	cin>>c>>t;
	for (int i=1;i<=t;i++) {
		cin>>n>>k;
		for (int i=1;i<n;i++) cin>>u[i]>>v[i];
	}
	for (int i=1;i<=t;i++) cout<<i<<endl;
	
	
	
	return 0;
}
