#include<bits/stdc++.h>
using namespace std;
char x[5];
char y[5];
int main(){
	for(int i=0;i<5;i++){
		cin>>x[i]; 
	}
	for(int i=0;i<5;i++){
		cin>>y[i];
	}
	if(x[1]==y[1]){
		cout<<"1";
	}else{
		cout<<"0";
		cout<<"0";
		cout<<"0";
		cout<<"0";
		return 0;
	}
	if(x[3]==y[3]){
		cout<<"1";
	}else{
		cout<<"0";
		cout<<"0";
		cout<<"0";
		return 0;
	}
	int q=0;
	if(x[4]=='A'||x[4]=='B'||x[4]=='C'){
		if(y[4]=='A'||y[4]=='B'||y[4]=='C'){
			q++;
		}
	}
	if(x[4]=='D'||x[4]=='F'){
		if(y[4]=='D'||y[4]=='F'){
			q++;
		}
	}
	if(q==0){
		cout<<"0";
		cout<<"0";
		return 0;
	}
	cout<<"1";
	if(x[4]-1==y[4]||x[4]+1==y[4]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
