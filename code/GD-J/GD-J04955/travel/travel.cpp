#include<bits/stdc++.h> 
using namespace std;

int main (){
	string a;
	getline(cin,a);
	if(a[0]==a[7]&&a[1]==a[8]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	} 
	if(a[3]==a[10]&&a[4]==a[11]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	} 
	if(a[5]=='A'||a[5]=='B'||a[5]=='C'){
		if(a[12]=='A'||a[12]=='B'||a[12]=='C'){
			cout<<1; 
		}
		else{
			cout<<0<<0;
			return 0;
		}
	}
	else if(a[5]=='F'||a[5]=='D'){
		if(a[12]=='F'||a[12]=='D'){
			cout<<1; 
		}
		else{
			cout<<0<<0;
			return 0;
		}
	}
	if(a[5]==a[12]+1||a[5]==a[12]-1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
