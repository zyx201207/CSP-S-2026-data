#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1;
	string s2;
	string s3;
	string s4;
	cin>>s1;
	cin>>s2;
	cin>>s3;
	cin>>s4;
	bool a=1,b=1,c=1,d=1;
	if(s1==s3)a=1;
	else a=0;
	if(s2[0]==s4[0]&&s2[1]==s4[1])b=1;
	else b=0;
	if((s2[2]>67&&s4[2]>67)||(s2[2]<=67&&s4[2]<=67))c=1;
	else c=0;
	if((s2[2]=='C'&&s4[2]=='A')||(s4[2]=='C'&&s2[2]=='A'))d=0;
	else d=1;
	if(a==0){
	cout<<"0000";
	return 0;
	}
	else if(b==0){
	cout<<"1000";
	return 0;
	}
	else if(c==0){
	cout<<"1100";
	return 0;
	}
	else cout<<"111"<<d;
	return 0;
}
