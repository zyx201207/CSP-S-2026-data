#include<bits/stdc++.h>
using namespace std;

int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1,s1,s2,c2;
	cin>>c1>>c2>>s1>>s2;
	bool a=0,b=0,c=0,d=0;
	if(c1==s1){
		a=1;
	}else if(c2[0]==s2[0]&&c2[1]==s2[1]){
		b=1;
		if(c2[2]=='A'&&s2[2]=='B') c=1,d=1;
		if(c2[2]=='B'&&s2[2]=='A') c=1,d=1;
		if(c2[2]=='D'&&s2[2]=='E') c=1,d=1;
		if(c2[2]=='E'&&s2[2]=='D') c=1,d=1;
		if(c2[2]=='D'&&s2[2]=='C') c=1,d=1;
		if(c2[2]=='C'&&s2[2]=='D') c=1,d=1;
		if(c2[2]=='E'&&s2[2]=='C') c=1;
		if(c2[2]=='C'&&s2[2]=='E') c=1;
	}
	cout<<a<<b<<c<<d;
	return 0;
}