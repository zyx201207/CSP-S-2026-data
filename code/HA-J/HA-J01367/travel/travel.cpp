#include<bits/stdc++.h>
//string start from 0!!!
using namespace std;
string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	//
	bool flag1=false;
	if(c1==c2){
		cout<<1;
		flag1=true;
	}
	else{
		cout<<0;
		flag1=false;
	}
//	if(c1==c2)cout<<1;
bool flag2=false;
	if(flag1==true&&s1[1]==s2[1]&&s1[0]==s2[0]){
		cout<<1;
		flag2=true;
	}
	else {
		cout<<0;
		flag2=false;
	}
	//
	bool flag3=false;
	if(flag1==true&&flag2==true&&(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='E')&&(s2[2]=='D'||s2[2]=='E')))&&s2[2]!=s1[2]){
		cout<<1;
		flag3=true;
	}
	else {
		cout<<0;
		flag3=false;
	}
	//
	bool flag4=false;
	if(flag1==true&&flag2==true&&flag3==true&&abs((int)s1[2]-(int)s2[2])==1){
		flag4=true;
		cout<<1;
	}
	else {
		cout<<0;
		flag4=false;
	}
	return 0;
}
