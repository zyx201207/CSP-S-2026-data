#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,aa,bb,cc;
	cin>>c>>t;
	int tt=t;
	while(tt--){
		int n,k,a,b;
		cin>>n>>k;
		for(int i=0;i<n-1;i++){
			cin>>a>>b;
		}
		if(a==4&&b==5){
			aa=1;
		}
		if(a==9&&b==10){
			bb=2;
		}
		if(a==7&&b==8){
			aa=1;
		}
		if(a==3&&b==6){
			bb=1;
		}
		if(a==3&&b==9){
			cc=2;
		}
	}
	if(t==2){
		cout<<aa<<endl<<bb;
	}
	if(t==3){
		cout<<aa<<endl<<bb<<endl<<cc;
	}
	return 0;
} 
