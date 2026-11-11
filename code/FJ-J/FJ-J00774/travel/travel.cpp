#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
 string s;
 string str;
 string a;
 string b;
 cin>>s>>str>>a>>b;
 int n=(s[0]-'0')*10+(s[1]-'0');
 int m=(a[0]-'0')*10+(a[1]-'0');
 if(n==m)cout<<"1";
 else cout<<"0";
  if(n==m){
      int x=(str[0]-'0')*10+(str[1]-'0');
      int y=(b[0]-'0')*10+(b[1]-'0');
      if(x==y){
      	cout<<"1";
		  if(str[2]=='A'&&b[2]!='D'&&b[2]!='E'||str[2]=='B'&&b[2]!='D'&&b[2]!='E'||str[2]=='C'&&b[2]!='D'&&b[2]!='E'){
      	cout<<"1";
      	if((str[2]-'0')==(b[2]-'0')+1||(str[2]-'0')+1==(b[2]-'0')){
      		cout<<"1";
   }
   else {
   	cout<<"0";
   }
} else {
   cout<<"0"<<"0";
}  
      }
      
	   else{
      	cout<<"0"<<"0"<<"0";
      }
    
  }
     else cout<<"0"<<"0"<<"0";
   
return 0;
}
