#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,ans;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans+='1';
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
				ans+='1';
				if(abs(s1[2]-s2[2])==1) ans+='1';
				else ans="1110";
			}
			else if((s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F'))
			ans+='1',ans+='1';
			else ans="1100";
		}
		else ans="1000";
	}
	else ans="0000";
	cout<<ans;
}
