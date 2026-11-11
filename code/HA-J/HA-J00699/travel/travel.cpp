#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool check(){
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		if(s4[2]=='A'||s4[2]=='B'||s4[2]=='C') return true;
		else return false;
	}
	else{
		if(s4[2]=='D'||s4[2]=='E') return true;
		else return false;
	}
}
bool c(){
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		if(s2[2]=='A'&&s4[2]=='C') return false;
		if(s2[2]=='C'&&s4[2]=='A') return false;
	}
	return true;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3) cout<<"0000";
	else{
		cout<<"1";
		if(s2[0]!=s4[0]||s2[1]!=s4[1]) cout<<"000";
		else{
			cout<<"1";
			if(!check()) cout<<"00";
			else{
				cout<<"1";
				if(c()) cout<<"1";
				else cout<<"0";
			}
		}
	}
	return 0;
}
