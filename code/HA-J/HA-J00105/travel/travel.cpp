#include <bits/stdc++.h>
using namespace std;

	int main(){
		freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);
		string c1,s1,c2,s2;
		cin>>c1>>s1>>c2>>s2;
		if(c1==c2){
			cout<<"1";
		}
		else cout<<"0";
		
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<"1";
		}
		else cout<<"0";
		
		string a=s1.substr(2,1),b=s2.substr(2,1);
		
		if(a=="C"&&b=="D") cout<<"0";
		else if(a=="D"&&b=="C") cout<<"0";
		else cout<<"1";
		
		if(a=="A"){
			if(b=="B") cout<<"1";
		}		
		else if(a=="B"){
			if(b=="C"||b=="A") cout<<"1";
		} 
		else if(a=="C"&&b=="B")cout<<"1";
		else if(a=="D"&&b=="F")cout<<"1";
		else if(a=="F"&&b=="D") cout<<"1";
		else cout<<"0";
		
		return 0;
	}

