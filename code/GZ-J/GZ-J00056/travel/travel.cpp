//GJ-J0056 贵阳市花溪第一中学 王梓诚 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	int a,b[4],x,y[4];
	cin>>a;
	for(int i=0;i<4;i++){
		cin>>b[i];
	}
	cin>>x;
	for(int i=0;i<4;i++){
		cin>>b[i];
	}
	if(a==x){
		cout<<'1';
	}
	else if(a!=x){
		cout<<"0000";
	}
	else if(b[0]==y[0]&&b[1]==y[1]){
		cout<<'1';
	}
	else if(b[0]!=y[0]||b[1]!=y[1]){
		cout<<"1000";
	}
	else if(b[2]>='A'&&b[2]<='C'&&y[2]>='A'&&y[2]<='C'){
		cout<<'1';
	}
	else if(b[2]>='D'&&b[2]<='F'&&y[2]>='D'&&y[2]<='F'){
		cout<<'1';
	}
	else if(b[2]>='A'&&b[2]<='C'&&y[2]>='A'&&y[2]<='C'||b[2]>='D'&&b[2]<='F'&&y[2]>='D'&&y[2]<='F'){
		cout<<"1100";
	}
	else if(b[2]+1==y[2]||b[2]==y[2]+1){
		cout<<'1';
	}else{
		cout<<'0';
	}
	
}
	
	
	
	
	
	
	
	
	
	
	
