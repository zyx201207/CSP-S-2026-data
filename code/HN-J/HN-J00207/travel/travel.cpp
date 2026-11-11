#include<bits/stdc++.h>
using namespace std;
string s,s1,ans;
int c,c1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c1>>s1;
	s="!"+s;
	s1="!"+s1;
	ans="";
	if(c==c1){
		ans=ans+'1';
	}else{
		ans=ans+'0';
	}
	if(ans=="1"&&s[1]==s1[1]&&s[2]==s1[2]){
		ans=ans+'1';
	}else{
		ans=ans+'0';
	}
	if(ans=="11"&&s[3]>='A'&&s[3]<='C'&&s1[3]>='A'&&s1[3]<='C'||ans=="11"&&s[3]>='D'&&s[3]<='F'&&s1[3]>='D'&&s1[3]<='F'){
		ans=ans+'1';
	}else{
		ans=ans+'0';
	}
	if(ans=="111"&&abs((s[3]-'0')-(s1[3]-'0'))==1){
		if(s[3]=='D'&&s1[3]=='C'||s1[3]=='D'&&s[3]=='C'){
			ans=ans+'0';
		}else{
			ans=ans+'1';
		}
	}else{
		ans=ans+'0';
	}
	cout<<ans;
	return 0;
}


