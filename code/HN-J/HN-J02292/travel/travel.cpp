#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1[1]==c2[1]){
       if(s1[1]==s2[1]){
          if(s1[2]='A' and s2[2]=='B'){
             cout<<"1111"<<endl;
             return 0;
	      }
	      if(s1[2]='A' and s2[2]=='C'){
             cout<<"1110"<<endl;
             return 0;
	      }
	      if(s1[2]='B' and s2[2]=='C'){
             cout<<"1111"<<endl;
             return 0;
	      }
	      if(s1[2]='C' and s2[2]=='A'){
             cout<<"1110"<<endl;
             return 0;
	      }
	      if(s1[2]='C' and s2[2]=='B'){
             cout<<"1111"<<endl;
             return 0;
	      }
	      if(s1[2]='C' and s2[2]=='D'){
             cout<<"1100"<<endl;
             return 0;
	      }
	      if(s1[2]='D' and s2[2]=='C'){
             cout<<"1100"<<endl;
             return 0;
	      }
	      if(s1[2]='D' and s2[2]=='E'){
             cout<<"1111"<<endl;
             return 0;
	      }
	      if(s1[2]='E' and s2[2]=='D'){
             cout<<"1111"<<endl;
             return 0;
	      }
	      if(s1[2]='D' and s2[2]=='A'){
             cout<<"1100"<<endl;
             return 0;
	      }
	      if(s1[2]='D' and s2[2]=='B'){
             cout<<"1100"<<endl;
             return 0;
	      }
	      if(s1[2]='E' and s2[2]=='C'){
             cout<<"1100"<<endl;
             return 0;
	      }
	      if(s1[2]='C' and s2[2]=='E'){
             cout<<"1100"<<endl;
             return 0;
	      }
	      if(s1[2]='B' and s2[2]=='D'){
             cout<<"1100"<<endl;
             return 0;
	      }
	      if(s1[2]='B' and s2[2]=='E'){
             cout<<"1100"<<endl;
             return 0;
	      }
	      if(s1[2]='E' and s2[2]=='B'){
             cout<<"1100"<<endl;
             return 0;
	      }
	      if(s1[2]='A' and s2[2]=='D'){
             cout<<"1100"<<endl;
             return 0;
	      }
	      if(s1[2]='A' and s2[2]=='E'){
             cout<<"1100"<<endl;
             return 0;
	      }
	      if(s1[2]='E' and s2[2]=='A'){
             cout<<"1100"<<endl;
             return 0;
	      }
	      if(s1[2]='B' and s2[2]=='A'){
             cout<<"1111"<<endl;
             return 0;
	      }
    }
    else if(s1[1]!=s2[1]){
	   cout<<"1000"<<endl;
	   return 0;
	   }
}
	else{
	cout<<"0000"<<endl;
	return 0;
	}
return 0;
}
