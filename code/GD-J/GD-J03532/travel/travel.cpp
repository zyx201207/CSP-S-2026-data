#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int nu1=(s1[0]-'0')*10+(s1[1]-'0');
	int nu2=(s2[0]-'0')*10+(s2[1]-'0');
	if(s1[2]=='D')s1[2]='E';
	if(s2[2]=='D')s2[2]='E';
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C'))cout<<1;
			else cout<<"0";
		}else cout<<"00";
		if(abs(nu1-nu2)+abs(s2[2]-s1[2])<=1)cout<<1;
		else cout<<0;
	}else cout<<"0000";
	return 0;
}
