#include <bits/stdc++.h>
using namespace std;
string ans="0";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)ans="1";
	else {
		cout<<"0000";
		return 0;
	}
	string x1,x2,y1,y2;
	x1=a2[0]+a2[1];
	x2=a2[2];
	y1=b2[0]+b2[1];
	y2=b2[2];
	if(x1==y1)ans+="1";
	else {
		cout<<"1000";
		return 0;
	}
	if(x2=="A"){
		if(y2=="B"||y2=="C")ans+="1";
		else ans+="0";
		if(y2=="B")ans+="1";
		else ans+="0";
		cout<<ans<<endl;
	}
	if(x2=="B"){
		if(y2=="A"||y2=="C")ans+="11";
		else ans+="00";
		cout<<ans<<endl;
	}
	if(x2=="C"){
		if(y2=="B"||y2=="A")ans+="1";
		else ans+="0";
		if(y2=="B")ans+="1";
		else ans+="0";
		cout<<ans<<endl;
	}
	if(x2=="D"){
		if(y2=="F")ans+="11";
		else ans+="00";
		cout<<ans<<endl;
	}
	if(x2=="F"){
		if(y2=="D")ans+="11";
		else ans+="00";
		cout<<ans<<endl;
	}
	return 0;
}
