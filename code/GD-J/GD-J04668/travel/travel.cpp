#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>s1>>b>>s2;
	if(a==b) cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<"1";
	else {
		cout<<"000";
		return 0;
	}
	if(s1[2]=='F'||s2[2]=='F'){
		if(s1[2]!='D'||s2[2]!='D') cout<<"00";
		else cout<<"11";
		return 0;
	} else if(s1[2]=='D'||s2[2]=='D'){
		if(s1[2]!='F'||s2[2]!='F')cout<<"00";
		else cout<<"11";
		return 0;
	}
	cout<<"1";
	 if(s1[2]=='B'){
		if(s2[2]=='A'||s2[2]=='C')cout<<"1";
	}else if(s2[2]=='B'){
		if(s1[2]=='A'||s1[2]=='C')cout<<"1";
	}else cout<<"0";
	return 0;
} 
