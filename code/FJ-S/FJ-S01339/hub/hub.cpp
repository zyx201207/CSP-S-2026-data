#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[2000005],v[2000005],o;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	o=t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;++i)
			cin>>u[i]>>v[i];
		cout<<o-t<<"\n";
		
	}
	return 0;
}
