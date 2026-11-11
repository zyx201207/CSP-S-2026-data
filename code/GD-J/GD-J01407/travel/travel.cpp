#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans="";
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else ans+="1";
	if(s1[0]==s2[0]&&s1[1]==s2[1])ans+="1";
	else{
		cout<<ans+"000";
		return 0;
	}
	bool a=(s1[2]=='D'||s1[2]=='F'),b=(s2[2]=='D'||s2[2]=='F');
	if(a==b)ans+="1";
	else{
		cout<<ans+"00";
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))ans+="1";
	else{
		cout<<ans+"0";
		return 0;
	}
	cout<<ans;
	return 0;
}
//mian bits\stdc++.h froepen travel.ans
//freopen ni bei pian le
