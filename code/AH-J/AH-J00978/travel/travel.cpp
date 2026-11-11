#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int a,b;
int f=0,f2=0,f3=0,f4=0;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>s1>>s2>>s3>>s4;
cout<<11;
	for(int i=0;i<s2.size();i++){
	    if(i==s2.size()-1){
			if(s2[i]>='A'&&s2[i]<='C'&&s4[i]>='A'&&s4[i]<='C'){
				a=s2[i],b=s4[i];
				if(a==b+1||a==b-1){
				   cout<<11;
				   return 0;
			   }
				else {
					cout<<10;
					return 0;
			    }
		  }
			if(s2[i]=='D'&&s4[i]=='F'||s4[i]=='D'&&s2[i]=='F') {
				   cout<<11;
				   return 0;
			   }
			else  {
				 cout<<00;
			 }
     }
}

  return 0;
}

