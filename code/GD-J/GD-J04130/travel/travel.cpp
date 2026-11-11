#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool e=false;
	bool s=false;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	bool flag=true;
	for(int i=0;i<2;i++){
		if(b[i]!=d[i]){
			flag=false;
		}
	}
	if(flag and a==c){
		cout<<"1"; 
	}
	else{
		cout<<"0";
	}
	if(b[2]=='A' or 'B' or'C' and d[2]=='A' or 'B' or'C' ){
		e=true;
	}	
	if(b[2]=='D' or 'F' and d[2]=='D' or 'F' ){
			e=true;
		}		
	if(flag and e and a==c){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(b[2]=='A'){
		if(d[2]=='B'){
			s=true;
		}
	}
	if(b[2]=='B'){
		if(d[2]=='A' or 'C'){
			s=true;
		}
	}
	if(b[2]=='c'){
		if(d[2]=='B'){
			s=true;
		}
	}
	if(b[2]=='D'){
		if(d[2]=='F'){
			s=true;
		}
	}
	if(b[2]=='F'){
		if(d[2]=='D'){
			s=true;
		}
	}
	if(flag and e and a==c and s){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
