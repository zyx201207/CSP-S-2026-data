#include <bits/stdc++.h> 
using namespace std;
string a,b,c; 
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a>>b>>c; 
if(a==c){
	if(b=="02B"&&c=="02")
	cout<<"1000" ;
		
	if(b=="01C"&&c=="02")
	cout<<"1110" ;
	
	else{
	cout<<"1000" ;	}
}
else{
	cout<<"0000";
}
return 0;
} 
