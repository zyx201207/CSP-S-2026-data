#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int uu;
bool kk;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>a>>b>>c>>d;
   if(a==c){
	cout<<"1";
	kk=true;
   }
else{
	cout<<"0";
	kk=false;
	}
	
  if(kk&&b[0]==d[0]&&b[1]==d[1]){
	cout<<"1";
	kk=true;
   }
else{
	cout<<"0";
	kk=false;
	}
	
   if(kk&&((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C'))){
	cout<<"1";
	kk=true;
  }
else{
	cout<<"0";
	kk=false;
	}
	
	uu=int(b[2]-d[2]);
  if(kk&&((uu==1||uu==-1)||((b[2]=='D'&&d[2]=='F')||(d[2]=='D'&&b[2]=='F')))){
	cout<<"1";
  }
  else{
	  cout<<"0";
	  }
return 0;
}
