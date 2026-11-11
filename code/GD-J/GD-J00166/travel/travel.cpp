#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2,ans;
int chk_ce(){
	if(s1[2]=='A'){
		if(s2[2]=='B')
			return 1;
		if(s2[2]=='C')
			return 2;
		return 3;
	}
	if(s1[2]=='B'){
		if(s2[2]=='C'||s2[2]=='A')
			return 1;
		return 3;
	}
	if(s1[2]=='C'){
		if(s2[2]=='B')
			return 1;
		if(s2[2]=='A')
			return 2;
		return 3;
	}
	if(s1[2]=='D'){
		if(s2[2]=='F')
			return 1;
		return 3;
	}
	if(s1[2]=='F'){
		if(s2[2]=='E')
			return 1;
		return 3;
	}
	return 3;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c1>>s1>>c2>>s2;
	ans="0000";
	if(c1==c2){
		ans[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans[1]='1';
			int t=chk_ce();
			if(t==1)
				ans[2]=ans[3]='1';
			else if(t==2)
				ans[2]='1';
		}
	}
	cout<<ans;
	return 0;
}
