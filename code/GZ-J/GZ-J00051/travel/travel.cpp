//Ìï•×¶÷GZ-J00051
#include<bits/stdc++.h>
using namespace std;
struct Node{
	string chexiang,weizhi;
}a[2];
string s1="ABC",s2="DF";
int func(int n){
	if(n>=0){
		return n;
	}
	return 0-n;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<=1;i++){
		cin>>a[i].chexiang>>a[i].weizhi; 
	}
	string R1=a[0].weizhi.substr(0,2);
	string R2=a[0].weizhi.substr(2,1);
	string X1=a[1].weizhi.substr(0,2);
	string X2=a[1].weizhi.substr(2,1);
	if(a[0].chexiang==a[1].chexiang){
		cout<<1;
		if((s1.find(R2)&&s1.find(X2))){
		cout<<1;
        if(R2=="A"&&X2=="B"||R2=="B"&&X2=="A"||R2=="B"&&X2=="C"||R2=="C"&&X2=="B"||R2=="D"&&X2=="F"||R2=="F"&&X2=="D"){
        	cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if((s2.find(R2)&&s2.find(X2))){
		cout<<1;
        if(R2=="A"&&X2=="B"||R2=="B"&&X2=="A"||R2=="B"&&X2=="C"||R2=="C"&&X2=="B"||R2=="D"&&X2=="F"||R2=="F"&&X2=="D"){
        	cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(s1.find(R2)&&s2.find(X2)||s1.find(R2)&&s2.find(X2)){
		cout<<0<<0;
	}
	else{
		cout<<0<<0;
	}
	}
	else{
		cout<<0<<0<<0<<0;
	}
	if(R1==X1){
		cout<<1;
		else{
			cout<<0;
		}
	
	if((s1.find(R2)&&s1.find(X2))){
		cout<<1;
        if(R2=="A"&&X2=="B"||R2=="B"&&X2=="A"||R2=="B"&&X2=="C"||R2=="C"&&X2=="B"||R2=="D"&&X2=="F"||R2=="F"&&X2=="D"){
        	cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if((s2.find(R2)&&s2.find(X2))){
		cout<<1;
        if(R2=="A"&&X2=="B"||R2=="B"&&X2=="A"||R2=="B"&&X2=="C"||R2=="C"&&X2=="B"||R2=="D"&&X2=="F"||R2=="F"&&X2=="D"){
        	cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(s1.find(R2)&&s2.find(X2)||s1.find(R2)&&s2.find(X2)){
		cout<<0<<0;
	}
	else{
		cout<<0<<0;
	}
	return 0;
} 
