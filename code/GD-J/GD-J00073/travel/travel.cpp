#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool b=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<'1';
	else {cout<<'0';b==0;}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&b)cout<<'1';
	else {cout<<'0';b==0;}
	if((max(s1[2],s2[2])<='C'||min(s1[2],s2[2])=='D')&&b)cout<<'1';
	else {cout<<'0';b==0;}
	if(abs(s1[2]-s2[2])==1&&b)cout<<'1';
	else cout<<'0';
	return 0;
} 
