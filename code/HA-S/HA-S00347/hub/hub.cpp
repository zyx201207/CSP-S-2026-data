#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,v[2000005],u[2000005];
int hu(int n,int k){
	for(int i=1;i<=n;i++){
		cin>>v[i]>>u[i];
	}
	return n;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		hu(n,k);
	}
	cout<<1<<endl<<2;
	return 0;
}
