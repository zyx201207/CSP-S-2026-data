#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t,n,k,u[5005],v[5005],r[5005];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		cout<<(n-k)/2<<'\n';
	}
	return 0;
} 
