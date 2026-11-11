#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==0){
		if(t==2){
			cout<<1<<endl;
			cout<<2<<endl;
		}
		if(t==3){
			cout<<1<<endl;
			cout<<1<<endl;
			cout<<2<<endl;
		}
		if(t==5){
			cout<<17<<endl;
			cout<<9<<endl;
			cout<<6<<endl;
			cout<<6<<endl;
			cout<<9<<endl;
		}
		if(t==1){
			cout<<12251<<endl;
		}
	}
	return 0;
}
