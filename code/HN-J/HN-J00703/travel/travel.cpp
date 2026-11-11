#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char ans[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1[0]==s1[0] && c1[1]==s1[1]){
		ans[0]='1';
	}
	else{
		ans[0]='0';
		ans[1]='0';
		ans[2]='0';
		ans[3]='0';
		cout<<ans;
		return 0;
	}
	if(c2[0]==s2[0] && c2[1]==s2[1]){
		ans[1]='1';
	}
	else{
		ans[1]='0';
		ans[2]='0';
		ans[3]='0';
		cout<<ans;
		return 0;
	}
	if(c2[2]<='C'&&s2[2]<='C'){
		ans[2]='1';
	}
	else if(c2[2]>='D'&&s2[2]>='D'){
		ans[2]='1';
	}
	else{
		ans[2]='0';
		ans[3]='0';
		cout<<ans;
		return 0;
	}
	if(c2[2]=='C'&&s2[2]=='D'){
		ans[3]='0';
	}
	else if(c2[2]=='D'&&s2[2]=='C'){
		ans[3]='0';
	}
	else if(c2[2]+1==s2[2] || c2[2]-1==s2[2]){
		ans[3]='1';
	}
	else if(c2[2]+1!=s2[2] || c2[2]-1!=s2[2]){
		ans[3]='0';
	}
	cout<<ans;
	return 0; 
} 
