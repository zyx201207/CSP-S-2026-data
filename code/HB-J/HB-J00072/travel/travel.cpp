#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int t1,t2,t3;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	c1==c2?t1=1,cout<<1:cout<<0;
	(s1[0]==s2[0]&&s1[1]==s2[1])&&t1==1?t2=1,cout<<1:cout<<0;
	if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){
		t1==1&&t2==1?t3=1,cout<<1:cout<<0;
	}
	else{
		cout<<0;
	}
	if(!((s1[2]=='A'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='C'))&&t1==1&&t2==1&&t3==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
