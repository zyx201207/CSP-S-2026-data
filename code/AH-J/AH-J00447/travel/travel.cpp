#include<bits/stdc++.h>
using namespace std;
int a,a1;
string b,b1;
bool c(string b,string b1){
	if(b[2]>='A'&&b[2]<='C'&&b1[2]>='A'&&b1[2]<='C')
	return true;
	else if((b[2]=='D'||b[2]=='F')&&(b1[2]=='D'||b1[2]=='F'))
	return true;
	else
	return false;
}
bool d(string b,string b1){
	if(abs(b[2]-b1[2])==1)
	return true;
	else
	return false;
}
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a>>b>>a1>>b1;
if(a==a1){
	cout<<1;
	if(b[0]==b1[0]&&b[1]==b1[1]){
	cout<<1;
		if(c(b,b1)){
	cout<<1;
	if(d(b,b1))
	cout<<1;
	else
	cout<<"0";
	}
	else
	cout<<"00";
	}
	else
	cout<<"000";
}
else
cout<<"0000";

fclose(stdin);
fclose(stdout);
return 0;
}
