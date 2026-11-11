#include<bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2;
string ans="1000";
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1!=c_2) {
		cout<<"0000";
		return 0;
	} else if(s_1[0]+s_1[1]==s_2[0]+s_2[1]) {
		ans[1]='1';
		if((s_1[2]!='C'&&(s_2[2]!='A'||s_2[2]!='B'))||(s_2[2]!='D'&&(s_1[2]!='E'))) {
			ans[2]='1';
			if(s_1[2]+1!=s_2[2]+0) {
				cout<<"1110";
				return 0;
			}else{
				ans[3]='1';
			}
			
		}else {
			cout<<"1100";
			return 0;
		}
	}
	else {
		cout<<"1000";
		return 0;
	}
	
	cout<<ans;
	return 0;
}
