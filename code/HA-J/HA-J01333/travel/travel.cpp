#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	string t1=s1.substr(0,2),t2=s2.substr(0,2);
	if(t1==t2&&c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	bool s1d=0,s2d=0;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') s1d=1;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') s2d=1;
	if(s1d==s2d&&t1==t2&&c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1d==s2d&&t1==t2&&c1==c2&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}