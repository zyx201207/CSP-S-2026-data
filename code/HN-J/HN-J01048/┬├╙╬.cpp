#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2,a,b,c,d;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		a="1";
	}
	if(s1[2]==s2[2] && s1[1]==s2[1]){
		b="0";
		c="0";
	}else{
		b="1";
		c="1";
	}
	d="1";
	cout<<a<<b<<c<<d;
	return 0;
} 
