#include<bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2;
bool check(){
	if((s_1[2]=='F'&&s_2[2]=='D')||(s_1[2]=='D'&&s_2[2]=='F'))return 1;
	if((s_1[2]=='A'&&(s_2[2]=='B'||s_2[2]=='C'))||(s_1[2]=='B'&&(s_2[2]=='A'||s_2[2]=='C'))||(s_1[2]=='C'&&(s_2[2]=='A'||s_2[2]=='B')))return 1;
	return 0;
}
bool check1(){
	if(s_1[2]=='D'||s_1[2]=='F')return 1;
	if(s_1[2]=='B'||s_2[2]=='B')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2)cout<<1;
	else {
		cout<<"0000";return 0;
	}
	if(s_1[1]==s_2[1]&&s_1[0]==s_2[0])cout<<1;
	else {
		cout<<"000";return 0;
	}
	if(check())cout<<1;
	else {
		cout<<"00";return 0;
	}
	if(check1())cout<<1;
	else cout<<"0";
	
	return 0;
} 
