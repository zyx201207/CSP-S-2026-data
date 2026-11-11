#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool r=false;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		r=true;
	}else{
		cout<<0;
	}for(int i=0;i<=1;i++){
		if(b[i]==d[i] and r==true){
			r=true;
		}else{
			r=false;
		}
	}if(r==true){
		cout<<1;
		
	}else{
		cout<<0;
		r=false;
	}if(b[2]>'C' and d[2]>'C' and r==true){
		cout<<1;
	}else if(b[2]<='C' and d[2]<='C' and r==true){
		cout<<1;
	}else{
		cout<<0;
		r=false;
	}if(b[2]>'C' and d[2]>'C' and r==true){
		cout<<1;
	}else if(b[2]=='B' and d[2]=='A' and r==true){
		cout<<1;
	}else if(b[2]=='B' and d[2]=='C' and r==true){
		cout<<1;
	}else if(d[2]=='B' and b[2]=='A' and r==true){
		cout<<1;
	}else if(d[2]=='B' and b[2]=='C' and r==true){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
