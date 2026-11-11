#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else
		cout<<"1";
	if(s1[0]==s2[0]&&s1[1]==s2[1])
		cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='A'||s2[2]=='B')||(s2[2]=='C'&&s1[2]=='B')||(s2[2]=='A'&&s1[2]=='C')||(s2[2]=='A'||s1[2]=='B'))
		cout<<"1";
	else{
		cout<<"0";
	}
	if((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='A'||s2[2]=='B'))
		cout<<"1";
	else
		cout<<"0";
	return 0;
}
/*
哎，虽然第一题花了亿点点时间，不过A了吧，嗯，五个样例都过了，我真的太牛叉了
看我代码干啥，不处 
*/
