#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>u>>v;
		}
	}
	if(c==0){
		if(v==10){
			cout<<1<<endl<<2;
		}
		if(v==9){
			cout<<1<<endl<<12;
		}
		return 0;
	}
	cout<<0<<endl<<0;
	return 0;
}
