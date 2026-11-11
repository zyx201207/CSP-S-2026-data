#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travle.in","r",stdin);
	freopen("travle.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1==c2 && s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	char s1_cr,s2_cr;
	s1_cr=s1[2];
	s2_cr=s2[2];
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && (s1_cr!='C' && s2_cr!='D') && (s1_cr!='D' && s2_cr!='C')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && (s1_cr-1==s2_cr || s1_cr+1==s2_cr) && (s1_cr!='C' && s2_cr!='D') && (s1_cr!='D' && s2_cr!='C')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
 }
