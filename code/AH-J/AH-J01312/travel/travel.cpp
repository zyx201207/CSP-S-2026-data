#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,s="0000";
bool f=true,k[100];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	k['D']=true,k['F']=true;
	if(c1==c2) s[0]='1';
	else f=false;
	if(f==false){
		cout<<s;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) s[1]='1';
	else f=false;
	if(f==false){
		cout<<s;
		return 0;
	}
	if(k[int(s1[2])]==k[int(s2[2])]) s[2]='1';
	else f=false;
	if(f==false){
		cout<<s;
		return 0;
	}
	if(k[int(s1[2])]==false){
		if(s1[2]=='A'&&s2[2]!='B') f=false;
		else if(s1[2]=='C'&&s2[2]!='B') f=false;
	}
	if(f==false){
		cout<<s;
		return 0;
	}
	s[3]='1';
	cout<<s;
	return 0;
}
