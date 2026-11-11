#include <bits/stdc++.h>
using namrspace std;
int main(){
	freopen("travel.in","r"stdin);
	freopen("travel.out","w"stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int s;
	if(a==c){
		s=1;
	}else{
		s=0;
	}
	if(s==0){
		cout<<0000;
		s=1;
	}else if(b[0]+b[1]!=d[0]+d[1]){
		s=0;
	}else if(b[0]+b[1]==d[0]+d[1]){
		s=0;
	}
	if(s=0){
		cout<<000;
		s=1;
	}else if(b[2]=="ABC"&&d[2]=="ABC"){
		cout<<1;
		
	}else if(b[2]=="DE"&&d[2]=="DE"){
		cout<<1;
		s=1
	}else {
		s=0;
	}
	if(s==0){
		cout<<00;
		s=1;
		
	}else if(s=1){
		cout<<1;
		
	}else if(b[2]=="A" && d[2]=="B"){
		cout<<1;
		
	}else if(b[2]=="B" && d[2]=="C"){
		cout<<1;
		
	}else{
		cout<<0;
	}
}
