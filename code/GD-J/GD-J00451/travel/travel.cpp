#include <bits/stdc++.h>
using namespace std;
int c1,c2,a,b;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	a=int(s1[0]-'0')*10+int(s1[1]-'0');
	b=int(s2[0]-'0')*10+int(s2[1]-'0');
	if(a==b) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'&&abs(s1[2]-s2[2])!=1){
		cout<<0;
	}else{
		cout<<1;
	}
	return 0;
}
