#include<bits/stdc++.h>
using namespace std;
string a,an,b,bn; 
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout); 
	cin>>a>>an>>b>>bn;
	if(a==b){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(a==b && an[0]==bn[0] && an[1]==bn[1]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(a==b && an[0]==bn[0] && an[1]==bn[1]){
		if(an[2]>='A'&&an[2]<='C' && bn[2]>='A'&&bn[2]<='C'){
			cout<<"1";
		} 
		else if(an[2]>='D'&&an[2]<='F' && bn[2]>='D'&&bn[2]<='F	'){
			cout<<"1";
		} 
		else cout<<"0";
	}
	else{
		cout<<"0";
	}
	if(a==b && an[0]==bn[0] && an[1]==bn[1]){
		if(an[2]>='A'&&an[2]<='C' && bn[2]>='A'&&bn[2]<='C' && an[2]==bn[2]+1 || an[2]+1==bn[2]){
			cout<<"1";
		} 
		else if(an[2]>='D'&&an[2]<='F' && bn[2]>='D'&&bn[2]<='F' && an[2]==bn[2]+1 || an[2]+1==bn[2]){
			cout<<"1";
		} 
		else cout<<"0";
	}
	else{
		cout<<"0";
	}
	return 0;
}
