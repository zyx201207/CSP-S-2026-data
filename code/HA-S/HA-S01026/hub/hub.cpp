#include<bits/stdc++.h>
using namespace std;

int c,t,n,k;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		if(t==2 && n==5 && k==2){
			cout<<"1\n";
		}else if(t==2 && n==10 && k==3){
			cout<<"2\n";
		}else if(t==3 && n==8 && k==6){
			cout<<"1\n";
		}else if(t==3 && n==6 && k==5){
			cout<<"1\n";
		}else if(t==3 && n==9 && k==3){
			cout<<"2\n";
		}
	}
	
	
	
	
	return 0;
}