#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x=0;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		x+=4;
	for(int i=1;i<=x;i++){
		cout<<0;
	}
	return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}else if((b[0]==d[0]&&b[1]!=d[1])||(b[0]!=d[0]&&b[1]==d[1])){
		x+=3;
		for(int i=1;i<=x;i++){
		cout<<0;
		}
		return 0;
	}
	if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D')){
		cout<<1;
	}else if((b[2]>='D'&&d[2]<='C')||(b[2]<='C'&&d[2]>='D')){
		x+=2;
		for(int i=1;i<=x;i++){
			cout<<0;
		}
		return 0;
	}
	if(abs(b[2]-d[2])==1){
		cout<<1;
	}else{
		x+=1;
		for(int i=1;i<=x;i++){
			cout<<0;
		}
		return 0;
	}
	return 0;
} 
