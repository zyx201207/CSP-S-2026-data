#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,u="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		u="0000";
		cout<<u;
		return 0;
	}
	u=u+'1';
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		u=u+"000";
		cout<<u;
		return 0;
	}
	u=u+'1';
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		if(s2[2]!='A'&&s2[2]!='B'&&s2[2]!='C'){
			u=u+"00";
			cout<<u;
			return 0;
		}
		u=u+"1";
		if(s1[2]=='B'||s2[2]=='B'){
			u=u+"1";
			cout<<u;
			return 0;
		}
		u=u+"0";
		cout<<u;
		return 0;
	}
	if(s1[2]=='D'||s1[2]=='F'){
		if(s2[2]!='D'&&s2[2]!='F'){
			u=u+"00";
			cout<<u;
			return 0;
		}
		u=u+"11";
		cout<<u;
		return 0;
	}
	return 0;
}

