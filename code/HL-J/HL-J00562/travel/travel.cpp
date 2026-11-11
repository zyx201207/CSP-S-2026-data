#include <bits/stdc++.h>
using namespace std;
string a;
string b;
string c;
string d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[1]==d[1]){
		   cout<<"1";
		   int as1=b[2];
	       int as2=d[2];
	       if(b[2]=='C'&&d[2]=='D'){
	       	 	cout<<"00";
	       	 	return 0;
		   }
		   else if(b[2]=='D'&&d[2]=='C'){
		   	   cout<<"00";
		   	   return 0;
		   }
		   else{
		   	cout<<"1";
		   	if(abs(as1-as2)==1){
		   		cout<<"1";
			}
			else{
				cout<<"0";
			}
		   }
	    }
	    else{
		   cout<<"000";
		   return 0;
	    }
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
