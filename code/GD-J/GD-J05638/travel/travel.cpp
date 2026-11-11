#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	string l1,l2;
	l1+=s1[0];
	l1+=s1[1];
	l2+=s2[0];
	l2+=s2[1];
	if(l1==l2){
		cout<<1;
		if((s1[2]<='C'&&s2[2]<='C')||((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))) cout<<"1";
		else{
			cout<<"00";
			return 0;
		}
	}
	else{
		cout<<"000";
		return 0;
	}
	if(s1[2]+1==s2[2]||s1[2]-1==s2[2])cout<<"1";
	else cout<<"0";
		
	return 0;
}
