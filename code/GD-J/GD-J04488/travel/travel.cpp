#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		ans+='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans+='1';
			if('A'<=s1[2]<='C'&&'A'<=s2[2]<'C'){
				ans+='1';
				if(char(s1[2]+1)==s2[2]||char(s2[2]+1)==s1[2]) ans+='1';
				else ans+='0';
			}
			else if('D'<=s1[2]<='F'&&'D'<=s2[2]<='F') ans+="11";
			else ans+="00";
		}
		else ans+="000";
	}
	else ans="0000";
	cout<<ans;
	return 0;
}
