#include<bits/stdc++.h>
using namespace std;
int main(){
	char c1[128128];
	
	char s1[128128];
	char c2[128128];
	char s2[128128];
	cin>>c1>>s1>>c2>>s2;
	
    if(c1[0]==c2[0] and c1[1]==c2[1]){
		cout<<"1";
		 if(s1[0]==s2[0] and s1[1]==s2[1]){
		cout<<"1";
		     if(s1[2]<'D' and s2[2]<'D'){		
				 cout<<"1";
				     if(s1[2]-s2[2]==1 or s2[2]-s1[2]==1){
					 cout<<"1";
				     }else{
				     cout<<"0";
				      }
				  }else{
				       if(s1[2]>'C' and s2[2]>'C'){
				       cout<<"1";
				          if(s1[2]-s2[2]==1 or s2[2]-s1[2]==1){
					      cout<<"1";
				          }else{
				          cout<<"0";
			              }
				       }else{
				  cout<<"0"<<"0";
		         }   
					 
				 }
				} else{
					cout<<"0"<<"0"<<"0";
					
				 }
			 }else{
				 cout<<"0"<<"0"<<"0"<<"0";
			 }
			 return 0;
		 }



