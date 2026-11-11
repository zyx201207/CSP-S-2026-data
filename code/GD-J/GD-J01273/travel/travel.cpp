#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	int a,b;
	if(s1[2]>='D') a=1;
	else a=0;
	if(s2[2]>='D') b=1;
	else b=0;
	if(a==b) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(a==1) cout<<"1";	
	else{
		int cnt=0;
		if(s1[2]=='B') cnt++;
		else if(s2[2]=='B') cnt++;
		if(cnt) cout<<"1";
		else cout<<"0";
	}
	return 0;
}
