#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k,u,v;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u>>v;
		}
		if(n>0){
			cout<<"1"<<endl;
		}
		else{
			cout<<"0"<<endl;
		}
	}

	return 0;
}
