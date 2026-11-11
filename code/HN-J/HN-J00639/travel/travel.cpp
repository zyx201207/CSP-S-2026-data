#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
//#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int num,num2,a[10]={};
	string s,n;
	cin>>num;
	cin>>s;
	cin>>num2;
	cin>>n;
	int i=2;
	if(num==num2){
		//if(n[i]>='A' && n[i]<='C' && s[i]>='A' && s[i]<='C' && (s[0]==n[0]) &&(s[1]==n[1]))	a[1]=1;
		a[1]=1;
		if((s[0]==n[0]) &&(s[1]==n[1]))	a[2]=1;
		if(n[i]>='A' && n[i]<='C' && s[i]>='A' && s[i]<='C')	a[3]=1;
		else if(n[i]>='D' && n[i]<='F' && s[i]>='D' && s[i]<='F')	a[3]=1;
		if(s[0]==n[0] && s[1]==n[1] && (s[i]-n[i] == 1||s[i]-n[i] == -1) && n[i]>='A' && n[i]<='C' && s[i]>='A' && s[i]<='C')	a[4]=1;
		else if(s[0]==n[0] && s[1]==n[1] && (s[i]-n[i] == 1||s[i]-n[i] == -1) && n[i]>='D' && n[i]<='F' && s[i]>='D' && s[i]<='F')    a[4]=1;
		
	
	}	else{
		for(int j=1;j<=4;j++){
		cout<<"0";
	}
	cout<<endl;
	return 0;
}
	for(int j=1;j<=4;j++){
		if(a[j]==1){
			cout<<a[j];
		}   else{
			cout<<0; 
		}
		
	}
	cout<<endl; 
	return 0;
} 
//02 号车厢是二等座车厢。01A和01B在同一节车厢、同一排、过道的同一侧，并
//且相邻，因此输出1111。





/*if(s[i-1]+s[i]==n[i-1]+n[i]){
			if(s[i+1]>='A'&&s[i+1]<='C'){
				a[1]=1;
				a[2]=1;
				a[3]=1;
				
			} else if(s[i+1]>='A'&&s[i+1]<='F'){
				a[1]=0;
				a[2]=1;
			}
			if(s[i+1]-n[i+1]==1||s[i+1]-n[i+1]-1){
					a[4]=1;
			}
		}*/
//02 02B 02 01A

