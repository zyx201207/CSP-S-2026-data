#include <bits/stdc++.h>
using namespace std;
string n1,n2;
string c1,c2;
bool fmy=false;
bool samed(){
	if(abs(c1[2]-c2[2]) == 1 && ( c1[2]!='C' && c2[2]!='D' || c1[2]!='D' && c2[2]!='C' ) ){
		return true;
	}
	return false;
}
int check(){
	if(n1==n2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	
	if((c1[2]=='A'&&c2[2]=='D')||(c1[2]=='A'&&c2[2]=='F')||(c1[2]=='B'&&c2[2]=='D')||(c1[2]=='B'&&c2[2]=='F')||(c1[2]=='C'&&c2[2]=='D')||(c1[2]=='C'&&c2[2]=='F')){
		cout<<"00";
		return 0;
	}
	else if((c1[2]=='D'&&c2[2]=='A')||(c1[2]=='F'&&c2[2]=='A')||(c1[2]=='D'&&c2[2]=='B')||(c1[2]=='F'&&c2[2]=='B')||(c1[2]=='D'&&c2[2]=='C')||(c1[2]=='F'&&c2[2]=='C')){
		cout<<"00";
		return 0;
	}else cout<<1;
	
	if(samed()){
		cout<<1;
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1>>c1>>n2>>c2;
	check();
	return 0;
}
