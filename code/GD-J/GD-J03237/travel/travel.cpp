#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans="";
	if(c1!=c2){
		ans+="0000";
	}
	else{
		ans+='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans+='1';
			if(('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
				ans+='1';
				if(char(s1[2])-char(s2[2])==1||char(s2[2])-char(s1[2])==1||((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))){
					ans+='1';
				}
				else{
					ans+='0';
				}
			}
			else{
				ans+="00";
			}
		}
		else{
			ans+="000";
		}
	}
	cout<<ans;

	return 0;
}

