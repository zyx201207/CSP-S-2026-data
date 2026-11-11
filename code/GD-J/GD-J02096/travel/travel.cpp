#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,ans;
bool f,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ans.resize(4);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]='1';
	}
	else ans[0]='0',b=1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&!b){
		ans[1]='1';
		f=1;
	}
	else ans[1]='0';
	ans[3]='0',ans[2]='0';
	if(f){
		if(s1[2]=='D'&&s2[2]=='F') ans[2]='1',ans[3]='1';
		else if(s1[2]=='F'&&s2[2]=='D') ans[2]='1',ans[3]='1';
		else if(s1[2]=='A'&&s2[2]=='B') ans[2]='1',ans[3]='1';
		else if(s1[2]=='B'&&s2[2]=='A') ans[2]='1',ans[3]='1';
		else if(s1[2]=='B'&&s2[2]=='C') ans[2]='1',ans[3]='1';
		else if(s1[2]=='C'&&s2[2]=='B') ans[2]='1',ans[3]='1';
		else if(s1[2]=='A'&&s2[2]=='C') ans[2]='1';
		else if(s1[2]=='C'&&s2[2]=='A') ans[2]='1';
	}
	cout<<ans;
	return 0;
}
