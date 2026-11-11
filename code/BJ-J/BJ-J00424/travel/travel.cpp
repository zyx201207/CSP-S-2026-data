#include<bits/stdc++.h>
using namespace std;
bool a1=0,a2=0,a3=0,a4=0;
string c1,s1,c2,s2;
bool chk1(string st1,string st2){
	char a=st1[2],b=st2[2];
	bool b1,b2;
	if(a=='F'||a=='D') b1=1;
	else b1=0;
	if(b=='F'||b=='D') b2=1;
	else b2=0;
	return b1==b2;
}
bool chk2(string ss,string sss){
	char a=ss[2],b=sss[2];
	if(a+b=='A'+'B') return 1;
	if(a+b=='C'+'B') return 1;
	if(a+b=='F'+'D') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1==c2);
	cout<<(c1==c2&&(s1[0]==s2[0]&&s1[1]==s2[1]));
	cout<<((c1==c2&&(s1[0]==s2[0]&&s1[1]==s2[1]))&&(chk1(s1,s2)));
	cout<<(((c1==c2&&(s1[0]==s2[0]&&s1[1]==s2[1]))&&(chk1(s1,s2)))&&(chk2(s1,s2)));
	return 0;
}
