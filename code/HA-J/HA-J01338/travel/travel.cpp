#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
    	cout<<"0000";
    	return 0;
	}
	a=int(s1[0]-'0')*10+s1[1];
	b=int(s2[0]-'0')*10+s2[1];
	if(a!=b){
		cout<<1000;
		return 0;
	}
	if(s1[2]=='E'){
		if(s2[2]!='D'){
		   cout<<1100;
		   return 0;
	    }
	}
	if(s1[2]=='D'){
		if(s2[2]!='E'){
		   cout<<1100;
		   return 0;
		}
	}
	if(s1[2]=='A'){
		if(s2[2]=='D'||s2[2]=='E'){
		   cout<<1100;
		   return 0;
		}
	}
	if(s1[2]=='B'){
		if(s2[2]=='D'||s2[2]=='E'){
		   cout<<1100;
		   return 0;
		}
	}
	if(s1[2]=='C'){
		if(s2[2]=='E'||s2[2]=='D'){
		   cout<<1100;
		   return 0;
		}
	}
	if(s1[2]=='C'&&s2[2]=='A'){
		cout<<1110;
		return 0;
	}
	if(s1[2]=='A'&&s2[2]=='C'){
		cout<<1110;
		return 0;
	}
	cout<<1111;
	return 0;
}