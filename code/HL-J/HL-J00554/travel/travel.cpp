#include<bits/stdc++.h>
using namespace std;
int c1,c2,a,b,c,d;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) a=1;
	else{
		cout<<"0000";
		return 0;
	}
	if((s1[0]-'0')*10+s1[1]-'0'==(s2[0]-'0')*10+s2[1]-'0'){
		b=1;
	}
	else{
		cout<<"1000";
		return 0;
	}
	if(s1[2]<'D'&&s2[2]<'D') c=1;
	else if(s1[2]>'C'&&s2[2]<'C') c=1;
	else {
		cout<<"1100";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1) d=1;
	cout<<a<<b<<c<<d;
	return 0;
}

