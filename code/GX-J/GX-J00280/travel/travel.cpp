#include<bits/stdc++.h>
using namespace std;
int R,X;
string r2,x2;
bool syq=0;
int main(){
	cin>>R>>r2>>X>>x2;
	if(R==X)cout<<"1";
	else {
	cout<<"0";
	syq=1;
	}	
	if(syq==0){
	(r2[0]==x2[0]&&r2[1]==x2[1]){
	cout<<"1";
	}
	else {cout<<"0";
	if(r2[2]=='A'||r2[2]=='B'||r2[2]=='C'){
		R=1;
	}
	else R=0;
	if(x2[2]=='A'||x2[2]=='B'||x2[2]=='C'){
		X=1;
	}
	else X=0;
	if(R==X){
	cout<<"1";
	}
	else{
			cout<<"0";
			return 0;
	}
	if(r2[2]=="D"||r2[2]=='F'){
	if(x2[2]=='D'||x2[2]=='F')cout<<"1";
	else cout<<"0";	
	}
	else if(r2[2]=="A"||r2[2]=='C'){
		if(x2[2]=='B')cout<<"1";
		else cout<<"0";
	}
	else if(x2[2]=='A'||x2[2]=='C')cout<<"1";
	else cout<<"0";
	return 0;
}
