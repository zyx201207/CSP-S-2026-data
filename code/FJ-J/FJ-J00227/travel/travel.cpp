#include<bits/stdc++.h>
using namespace std;
string s,s1,x,x1;
int main(){
	//Trick||Treat!
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>x>>x1;
	if(s==x)cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	if(s1[0]==x[0]&&s1[1]==x1[1])cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if((s1[2]=='F' && x1[2]=='D') || (s1[2]=='F' && x1[2]=='D')) cout<<"11";
	else if(s1[2]!='F' && s1[2]!='D' && x1[2]!='F' && x1[2]!='D'){
		if(s1[2]+1==x1[2]||s1[2]-1==x1[2])cout<<"11";
		else cout<<"10";
	}
	else cout<<"00";
	return 0;
}
