#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ans="";
	string a1,a2,b1,b2;
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2) ans+='1';
	else{
		ans="0000";
		cout<<ans;
		return 0;
	}
	string cb1=b1.substr(0,2);
	string cb2=b2.substr(0,2);
	if(cb1==cb2) ans+='1';
	else{
		ans="1000";
		cout<<ans;
		return 0;
	}
	char db1=b1[2];
	char db2=b2[2];
	bool ddb1=0;
	bool ddb2=0;
	if(db1=='D'||db1=='F') ddb1=1;
	if(db2=='D'||db2=='F') ddb2=1;
	if(ddb1==ddb2) ans+='1';
	else{
		ans="1100";
		cout<<ans;
		return 0;
	}
	if(ddb1==1){
		ans="1111";
		cout<<ans;
		return 0;
	}
	if(ddb1==0){
		if(db1=='A'&&db2=='C') ans="1110";
		else if(db1=='C'&&db2=='A') ans="1110";
		else ans="1111";
		cout<<ans;
		return 0;
	}
	return 0;
}
