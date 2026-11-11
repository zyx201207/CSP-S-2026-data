#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string res;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	res="0000";
	if(c1==c2) res[0]='1';
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) res[1]='1';
	else{
		cout<<"1000";
		return 0;
	}
	if(s1[2]<='C'&&s2[2]<='C'){
		res[2]='1';
		if(s1[2]=='B'||s2[2]=='B') res[3]='1';
		else res[3]='0';
	}
	else if(s1[2]>='D'&&s2[2]>='D'){
		res[2]='1',res[3]='1';
	}
	else res[2]='0';
	for(int i=0;i<=3;i++) cout<<res[i];
	return 0;
} 
