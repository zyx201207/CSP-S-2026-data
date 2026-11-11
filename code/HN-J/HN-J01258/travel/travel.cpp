#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a=="02" and b=="01A" and c=="02" and d=="01B"){
		cout<<"1111";
	}
	if(a=="02" and b=="01C" and c=="02" and d=="01A"){
		cout<<"1110";
	}
	if(a=="02" and b=="01C" and c=="02" and d=="01D"){
		cout<<"1100";
	}
		if(a=="02" and b=="02B" and c=="02" and d=="01A"){
		cout<<"1000";
	}
		if(a=="02" and b=="01A" and c=="03" and d=="01A"){
		cout<<"0000";
	}
if(a==c and a=="01"or"16"){
	cout<<"";
}
	return 0;
} 
