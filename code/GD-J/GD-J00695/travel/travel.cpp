#include<bits/stdc++.h>
using namespace std;
string s,ss,c,ans,cc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>s>>cc>>ss;
	ans="0000";
	if(c==cc)ans[0]='1';
	else{
		cout<<"0000";
		return 0;
	}
	string sss=s.substr(0,2),ssss=ss.substr(0,2);
	if(sss==ssss)ans[1]='1';
	else{
		cout<<ans;
		return 0;
	}
	if(s[2]=='F'||s[2]=='D'){
		if(ss[2]=='D'||ss[2]=='F'){
			ans[2]='1';ans[3]='1';
		}
	}else{
		if(ss[2]=='A'||ss[2]=='B'||ss[2]=='C'){
			ans[2]='1';
			if(abs((int)s[2]-ss[2])==1)ans[3]='1';
		}
	}
	cout<<ans;
	return 0;
}
