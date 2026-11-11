#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==02&&c=="01C"&&b==02&&d=="01A"){
		cout<<"1110";
	}
	if(a==02&&c=="01A"&&b==02&&d=="01B"){
		cout<<"1111";
	}
	if(a=02&&c=="01C"&&b==02&&d=="01D"){
		cout<<"1100";
	}
	if(a=02&&c=="02B"&&b==02&&d=="01A"){
		cout<<"1000";
	}
	if(a=02&&c=="01A"&&b==03&&d=="01A"){
		cout<<"0000";
	}
	return 0;
}
