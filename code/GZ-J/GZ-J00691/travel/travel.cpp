//GZ-J00691 遵义市新蒲新区滨湖中学 祝国城 
#include <bits/stdc++.h>
using namespace std;
int main() {
	froepen("travel.in","r","stdin");
	froepen("travel.out","w","stdout");
	string a;
	int s=0,d=0;
	cin>>a;
	if(a[1]==a[7]){
		cout<<'1';
	}else{
		cout<<'0';
	}
	
	if(a[2]==a[8]){
		cout<<'1';
	}else{
		cout<<'0';
	}
	
	if(a[4]==a[10]){
		cout<<'1';
	}else{
		cout<<'0';
	}
	
	if(a[5]==a[11]){
		cout<<'1';
	}else if(a[6]=='A'&&a[12]=='B'){
		cout<<'1';
	}else if(a[6]=='B'&&a[12]=='A'){
		cout<<'1';
	}else if(a[6]=='B'&&a[12]=='C'){
		cout<<'1';
	}else if(a[6]=='E'&&a[12]=='D'){
		cout<<'1';
	}else if(a[6]=='D'&&a[12]=='E'){
		cout<<'1';
	}else {
		cout<<'0';
	}
	
	
	
	
	return 0;
}

