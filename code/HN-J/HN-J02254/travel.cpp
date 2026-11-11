#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(travel.in,"r",stdin);
	freopen(travel.out,"w",strout);
	string c1,s1,c2,s2,sc="";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) sc+='1';
	else sc+='0';
	if(c1==c2 && s1.substr(0,2)==s2.substr(0,2)) sc+='1';
	else sc+='0';
	if(c1==c2 && s1.substr(0,2)==s2.substr(0,2) && ((int(s1[2])>=int('D') && int(s2[2])>=int('D'))||(int(s1[2])<int('D') && int(s2[2])<int('D')))) sc+='1';
	else sc+='0';
	if(c1==c2 && s1.substr(0,2)==s2.substr(0,2) && ((int(s1[2])>=int('D') && int(s2[2])>=int('D'))||(int(s1[2])<int('D') && int(s2[2])<int('D') && (s1[2]=='B' || s2[2]=='B')))) sc+='1';
	else sc+='0';
	cout<<sc;
	return 0;
}
