#include <bits/stdc++.h>
using namespace std;


string c1,s1,c2,s2;
string ans="0000";	
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	bool flag=true;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&flag){
		ans[0]='1';
	}
	else{
		flag=false;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&flag){
		ans[1]='1';
	}
	else{
		flag=false;
	}
	if(((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'))&&flag){
		ans[2]='1';
	}
	else{
		flag=false;
	}
	if(flag&&(s1[2]+1==s2[2]||s1[2]-1==s2[2])){
		ans[3]='1';
	}
	else{
		flag=false;
	}
	cout<<ans;
	return 0;
}
