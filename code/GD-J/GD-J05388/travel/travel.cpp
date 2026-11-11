#include<iostream>
#include<string>
using namespace std;
string x1,x2,y01,y2;
int xf,yf;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>x2>>y01>>y2;
	if(y2[2]>='A'&&y2[2]<='C'){
		yf=1;
	}
	else{
		yf=0;
	}
	if(x2[2]>='A'&&x2[2]<='C'){
		xf=1;
	}
	else{
		xf=0;
	}
	
	if(x1==y01){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(x2[0]+x2[1]==y2[0]+y2[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((xf^yf)==1){
		cout<<"00";
		return 0;
	}
	else{
		cout<<1;
	}
	if(abs(int(y2[2]-x2[2]))==1||x2[2]=='D'&&y2[2]=='F'||x2[2]=='F'&&y2[2]=='D'){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
