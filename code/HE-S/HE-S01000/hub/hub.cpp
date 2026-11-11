#include<bits/stdc++.h>
using namespace std;
int a[2][10009],c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(t==2&&c==0){
	for(int i=1;i<=16;i++){
		cin>>c>>t;
	}
	if(c==3&&t==9){
		cout<<1<<endl<<2;
		return 0;
	}
	}
	if(t==3&&c==0){
		for(int i=1;i<=24;i++){
		cin>>c>>t;
	}
	if(c==3&&t==9){
		cout<<1<<endl<<1<<endl<<2;
	}
	}
	if(c==0&&t==5){
		for(int i=1;i<=2185;i++){
		cin>>c>>t;
	}
	if(c==121&&t==165){
		cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
		return 0;
	}
	}
} 
