#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		ans.push_back('1');
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans.push_back('1');
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
				ans.push_back('1');
				if((s1[2]-s2[2]==1)||(s1[2]-s2[2]==-1)){
					ans.push_back('1');
				}
				else ans="1110";
			}
			else ans="1100";
		}
		else ans="1000";
	}
	else ans="0000";
	cout<<ans;
	return 0;
}
