#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	int a[9]={0};
	string q[100];
	string k[100];
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
	 a[0]=1;}
	 else cout<<"0000";
	for(int i=0;i<s1.size();i++){
	  q[i]=s1[i];
	  }
	for(int i=0;i<s2.size();i++){
	  k[i]=s2[i];
	  }
	  if(q[0]==k[0])
	  {
	  if(q[1]==k[1])
	  a[1]=1;
	  else cout<<"1000";
	  }
	  if((q[2]=="A" && k[2]=="C")||(q[2]=="C" && k[2]=="A"))
      {
	  cout<<"1110";}
     else
	  if((q[2]=="A" && k[2]=="B")||(q[2]=="B" && k[2]=="C")||(q[2]=="B" && k[2]=="A")||(q[2]=="C" && k[2]=="B")){
	  	cout<<"1111";}
	    else
	      if((q[2]=="d" && k[2]=="e")||(q[2]=="e" && k[2]=="d"))
      {
      	    cout<<"1111";
	  }
	           else cout<<"1100";
 return 0;   
}
