//#include<stdc++/bits.h>
#include<iostream>
using namespace std;
int a=4;
string c1,s1,c2,s2;
int main(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		a--;
		if(s1[0]==s2[0] and s1[1]==s2[1]){
			cout<<1;
			a--;
			if((int(s1[2])<='C' and int(s2[2])<='C') or (int(s1[2])>'C' and int(s2[2])>'C')){
				cout<<1;
				a--;
				if(abs(int(s1[2])-int(s2[2]))==1){
					cout<<1;
					a--;
				}
			}
		}	
	}
	
	for(int i=1;i<=a;i++){
		cout<<0;
	}
	return 0;
} 
