#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4,ans="1111";
	cin>>s1>>s2>>s3>>s4;
	if(s2[2]=='D')s2[2]='E';
	if(s4[2]=='D')s4[2]='E';
	if(s1==s3){
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			if(s2[2]<='C'&&s4[2]<='C'||s2[2]>='E'&&s4[2]>='E'){
				if(abs(s2[2]-s4[2])!=1){
					ans[3]='0';
				}
			}else ans="1100";
		}else ans="1000";
	}else ans="0000";
	cout<<ans;
}
