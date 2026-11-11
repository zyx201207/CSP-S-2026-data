//观山湖中学 刘郅铖 GZ-J00274
#include<bits/stdc++.h>
using namespace std;

	string c1,s1,c2,s2;
	bool flag;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
	cout<<'1';
	flag=1;
	}
	else cout<<'0';
	if(flag){
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<'1';
	else cout<<'0';
	}
	else cout<<'0';
	if(flag){
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))cout<<'1';
	else cout<<'0';
	}
	else cout<<'0';
	}
	else cout<<'0';
	if(flag){
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){ 
	if(((s1[0]==s2[0]&&s1[1]==s2[1])&&s1[2]==s2[2]+1)||((s1[0]==s2[0]&&s1[1]==s2[1])&&s1[2]==s2[2]-1))cout<<'1';
	else cout<<'0';
	}
	else cout<<'0';
	}
	else cout<<'0';
}
