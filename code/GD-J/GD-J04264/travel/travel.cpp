#include<bits/stdc++.h>
using namespace std;
string ans;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		ans[1]='1';
	} else ans[1]='0';

	if(ans[1]=='1') {
		if(s1[0]==s2[0]&&s1[1]==s2[1]) {
			ans[2]='1';
		} else ans[2]='0';
	} else ans[2]='0';

	if(ans[2]=='1') {
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') {
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
				ans[3]='1';
			else ans[3]='0';
		}
	} else if(ans[2]=='1') {
		if(s1[2]=='D'||s1[2]=='F') {
			if(s2[2]=='D'||s2[2]=='F')
				ans[3]='1';
			else ans[3]='0';
		} else ans[3]='0';
	} else ans[3]='0';

	if(ans[3]=='1') {
		if(s1[2]=='A'||s1[2]=='B')
			if(s2[2]=='A'||s2[2]=='B')
				ans[4]='1';
			else ans[4]='0';
	} else if(ans[3]=='1') {
		if(s1[2]=='C'||s1[2]=='B')
			if(s2[2]=='C'||s2[2]=='B') {
				ans[4]='1';
			} else ans[4]='0';
	} else if(ans[3]=='1') {
		if(s1[2]=='D'||s1[2]=='F')
			if(s2[2]=='D'||s2[2]=='F')
				ans[4]='1';
			else ans[4]='0';
	} else ans[4]='0';

//	cout<<ans[4]<<endl;
	cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
	return 0;
}
