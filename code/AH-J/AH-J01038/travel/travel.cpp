#include<bits/stdc++.h>
using namespace std;
int x,y,c1,c2;
char a1,a2;
string s1,s2;
int f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	getline(cin,s1); 
    cin>>c2;
	getline(cin,s2); 

	if(c1==c2)
 { 
	f1=1;
	if(s1==s2){
		cout<<"0000";
		return 0;
	}
 } 
    else
 {
 	f1=0;
 } a1=s1[0]+s1[1];
   a2=s2[0]+s2[1];
   if(a1==a2)
   {
   	f2=1;
   	if(s1[2]!='C'||s1[2]!='D'&&s2[2]!='C'||s2[2]!='D'){
   		
   if(abs(int(s1[2])-int(s2[2]))==1){
   	f4=1;
   }
   else{
   	f4=0;
   }
}
   else
    {
   	f4=0;
   }
   } 
   else 
   {
   	f2=0;
   }
  if(s1[2]==s2[2])
  {
  	f3=1;
  	if(abs(int(a1)-int(a2))==1){
  		f4=1;
	  }
	  else{
	  	f4=0;
	  }
  }
  else
  {
  	f3=0; 
  } 
	
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
