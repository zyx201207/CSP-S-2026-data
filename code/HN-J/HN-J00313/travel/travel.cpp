#include<bits/stdc++.h>
using namespace std;
stuck c1,s1,c2,s2;
int main(){
	fropen("travel.in","r",stdin)
	fropen("travel.out","w",stdout)
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else cout<<"0";
	   if(s1[1]==s2[1]) cout<<"1";
	   else cout<<"0";
	      if(s1[2]>='A'&&s2[2]<='C'||s1[2]>='D'&&s2[2]<='F') cout<<"1";
	      else cout<<"0";
	         if(s1[2]='A'||'B'&&s2[2]='A'||"B") cout<<"1";
	         else if(s1[2]='B'||'C'&&s2[2]='B'||"C") cout<<"1";
	         else if(s1[2]='D'||'F'&&s2[2]='D'||"F") cout<<"1";
	cout<<c1<<s1<<c2<<s2;
	return 0;         
} 

