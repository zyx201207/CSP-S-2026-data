#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c!=cc){
		ans="0000";
	}else{
		if(s[0]!=ss[0]||s[1]!=ss[1]){
			ans="1000";
		}else if(s[2]=='A'&&(ss[2]=='D'||ss[2]=='F')){
			ans="1100";
		}else if(s[2]=='B'&&(ss[2]=='D'||ss[2]=='F')){
			ans="1100";
		}else if(s[2]=='C'&&(ss[2]=='D'||ss[2]=='F')){
			ans="1100";
		}else if((s[2]=='D'||s[2]=='F')&&(ss[2]=='A'||ss[2]=='B'||ss[2]=='C')){
			ans="1100";
		}else if(s[2]=='A'&&ss[2]=='C'){
			ans="1110";
		}else if(s[2]=='C'&&ss[2]=='A'){
			ans="1110";
		}else{
			ans="1111";
		}
	}
	
	cout<<ans;
	return 0;
}
