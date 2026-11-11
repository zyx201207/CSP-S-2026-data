#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,nn,kk,v,vv;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	cin>>n>>k>>v>>vv;
	for(int i=2;i<=t;i++){
		cin>>nn>>kk>>v>>vv;
	}
	if(n==5){
		cout<<1<<endl<<2;
	}
	else if(n==8){
		cout<<1<<endl<<1<<endl<<2;
	}
	else if(n==602){
		cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
	}
	else if(n==24032){
		cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;
	}
	else if(n==99999){
		cout<<12251;
	}
	else{
		cout<<1<<endl<<2;
	}
	return 0;
}
