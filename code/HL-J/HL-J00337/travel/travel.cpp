#include<bits/stdc++.h>
using namespace std;
string s1;
string s2;
string c1;
string c2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	 } else{
	 	cout<<0;
	 }
	if(s1.substr (0,2)==s2.substr(0,2)){
		 if(c1==c2){
	  	cout<<1;
		  }else{
		  	cout<<0;
		  }
		  }	else{
		  	cout<<0;
		  }
	if('A'<=s1[2]<='C'&&'A'<=s2[2]<='C'||'D'<=s1[2]<='F'&&'D'<=s2[2]<='F'){
		if(c1==c2){
	if(s1.substr (0,2)==s2.substr(0,2)){
		cout<<1;
	}else{
		cout<<0;
	}
    }else
    {
    	cout<<0;
	}
	} else{
		cout<<0;
	}
	 if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)
	 {
	 	if(c1==c2){
	if(s1.substr (0,2)==s2.substr(0,2)){
	if('A'<=s1[2]<='C'&&'A'<=s2[2]<='C'||'D'<=s1[2]<='F'&&'D'<=s2[2]<='F'){
	 	cout<<1;
	 }else
	 {
	 	cout<<0;
	 }
	}else{
	cout<<0; 
	}
	 }else{
	 	cout<<0;
	 }
   }else{
	cout<<0;
   }
	return 0;
}
