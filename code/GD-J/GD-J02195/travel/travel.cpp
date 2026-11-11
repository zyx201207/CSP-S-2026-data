#include<bits/stdc++.h>
using namespace std;
string x1,s1,x2,s2;
int c1,c2,a1,b1,a2,b2;
int x_to_int(string s){
	return (s[1]-'0')+(s[0]-'0')*10;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>s1>>x2>>s2;
	c1=x_to_int(x1);
	c2=x_to_int(x2);
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	a1=(s1[1]-'0')+(s1[0]-'0')*10;
	a2=(s2[1]-'0')+(s2[0]-'0')*10;
	if(a1!=a2){
		cout<<"000";
		return 0;
	}
	cout<<1;
	bool f = (s1[2]=='D' || s1[2]=='F') , g  = (s2[2]=='D' || s2[2]=='F');
	if(f!=g){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(abs(s1[2]-s2[2])==1)cout<<1;
	else cout<<0;
}
