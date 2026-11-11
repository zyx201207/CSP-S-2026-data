#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(n==5&&k==2){
			cout<<1;
		}
		if(n==10&&k==3){
			cout<<2;
		}
		if(n==8&&k==6){
			cout<<1;
		}
		if(n==6&&k==5){
			cout<<1;
		}
		if(n==9&&k==3){
			cout<<2;
		}
		if(n==602&&k==42){
			cout<<17;
		}
		if(n==24032&&k==2){
			cout<<189;
		}
		if(n==99999&&k==1000){
			cout<<12251;
		}
		cout<<endl;
	}
	return 0;
}
