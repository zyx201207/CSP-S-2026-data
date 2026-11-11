#include <bits/stdc++.h>
#include <string>;
using namespace std;
int mani(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	string c1,c2;
	char s1[105],s2[105];
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2 ){
		cout<<"1";
	}
	else if(s1[0]==s2[0] && (s1[1]+1==s2[1]||s1[1]-1==s2[1])){
		cout<<"1";
	}
	else if((s1[2]=="A"||s1[2]=="B"||s1[2]=="C" )&& (s2[2]=="A"||s2[2]=="B"||s2[2]=="C") || (s1[2]=="D" || s1[2]=="E" || s1[2]=="F" && s2[2]=="D"||s2[2]=="E"||s2[2]=="F")){
		cout<<"1";
	}
	else if(s1[2]+1=s2[2]||s1[2]-1=s2[2]){
		cout<<"1";
	}
	else{
		cout<<"0"; 
	}
	return 0;
}
