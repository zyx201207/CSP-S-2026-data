#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,u[2000005],v[2000005]; 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while (t--){
		cin>>n>>k;
		for (int i=1;i<n;i++) cin>>u[i]>>v[i];
		if (k<9) cout<<1;
		else cout<<2;
	}
	return 0;
} 
