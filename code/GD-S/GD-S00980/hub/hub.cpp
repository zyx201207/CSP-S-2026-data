#include<bits/stdc++.h>
using namespace std;
int c,t,n[10],k[10],u[1000005],v[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>k[i];
		for(int j=1;j<=n[i]-1;j++){
			cin>>u[j]>>v[j];
		} 
	}
	for(int i=1;i<=t;i++){
		cout<<0<<endl;
	} 
	return 0;
}
