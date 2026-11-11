#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(travel.in,"r",stdin);
	freopen(travel.out,"w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(s1[2]==s2[2]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if((s1[3]=="A"&&s2[3]=="B")||(s1[3]=="B"&&s2[3]=="C")||(s1[3]=="D"&&s2[3]=="F")||(s2[3]=="A"&&s1[3]=="B")||(s2[3]=="B"&&s1[3]=="C")||(s2[3]=="D"&&s1[3]=="F")){
		cout<<"1"<<"1"<<endl;
	}else if(s1[3]=="A"&&s2[3]=="C"||s2[3]=="A"&&s1[3]=="C"){
		cout<<"1"<<"0"<<endl;
	}else{
		cout<<"0"<<"0"<<endl;
	}
	return 0;
}
