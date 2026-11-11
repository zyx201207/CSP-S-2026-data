#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool f1(){
	if(s1[0]==s2[0]&&s1[1]==s2[1])return 1;
	else return 0;
}
bool f2(){
	if(abs(s1[2]-s2[2])<=1){
		if((s1[2]=='D'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='D'))return 0;
		else return 1;
	}
	else return 0;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	if(f1()&&c1==c2)cout<<1;
	else cout<<0;
	if((f1()&&c1==c2)&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')))cout<<1;
	else cout<<0;
	if((c1==c2)&&((f1()&&f2())))cout<<1;
	else cout<<0;
	return 0;
}
