#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
string ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)ans+="1";
	else ans+="0";
	if(ans[0]=='0'){
		ans+="000";
	}else{
		if(s1[0]==s2[0]&&s1[1]==s2[1])ans+="1";
		else ans+="0";
		if(ans[1]=='1'){
			if((s1[2]-'A'<=2&&s2[2]-'A'<=2)||(s1[2]-'A'>=3&&s2[2]-'A'>=3))ans+="1";
			else ans+="0";
			if(ans[2]=='1'){
				if(abs(s1[2]-s2[2])==1)ans+="1";
				else ans+="0";
			}else{
				ans+="0";
			}
		}else{
			ans+="00";
		}
	}
	cout<<ans;
	return 0;
}

