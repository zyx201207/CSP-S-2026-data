#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string ans;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)ans.push_back('1');
	else ans.push_back('0');
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1])ans.push_back('1');
	else ans.push_back('0');
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1]){
		if((s2[2]=='F'||s2[2]=='D')&&(s4[2]=='F'||s4[2]=='D')){
			ans.push_back('1');
		}else if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s4[2]=='A'||s4[2]=='B'||s4[2]=='C')){
			ans.push_back('1');
		}else{
			ans.push_back('0');
		} 
	}else{
		ans.push_back('0');
	}
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1]){
		if((s2[2]=='F'||s2[2]=='D')&&(s4[2]=='F'||s4[2]=='D')&&(s2[2]+1==s4[2]||s4[2]+4==s2[2])){
			ans.push_back('1');
		}else if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s4[2]=='A'||s4[2]=='B'||s4[2]=='C')&&(s2[2]+1==s4[2]||s4[2]+4==s2[2])){
			ans.push_back('1');
		}else{
			ans.push_back('0');
		} 
	}else{
		ans.push_back('0');
	}	
	cout<<ans<<'\n';
	return 0;
} 
