#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c!=cc){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s.substr(0,2)!=ss.substr(0,2)){
		cout<<"000";
		return 0; 
	}
	cout<<1;
	if((s[2]>='A'&&s[2]<='C')^(ss[2]>='A'&&ss[2]<='C')){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(s[2]<ss[2]) swap(s[2],ss[2]);
	if((s[2]=='B'&&ss[2]=='A')||(s[2]=='C'&&ss[2]=='B')||((s[2]=='F'&&ss[2]=='D'))) cout<<1;
	else cout<<0;
	return 0;
}
/*
02 01A 02 01B
02 01C 02 01A
02 02B 02 01A
02 01A 03 01A
02 01C 02 01D
*/
