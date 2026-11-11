#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	cin>>a>>b>>c>>d;
	if(a==c){
		printf("1");	
	}else{
		printf("0000");
		return 0;
	}
	string x="",y="";
	x+=b[0];
	x+=b[1]; 
	y+=d[0];
	y+=d[1]; 
	if(x==y){
		printf("1");
	}else{
		printf("000");
		return 0;
	}
	if(b[2]<='C'&&d[2]<='C'){
		printf("1");
	}else if(b[2]>'C'&&d[2]>'C'){
		printf("11");
		return 0;
	}else{
		printf("00");
		return 0;
	}
	if(abs(b[2]-d[2])==1){
		printf("1");
	}else cout<<0;
	return 0;
}
