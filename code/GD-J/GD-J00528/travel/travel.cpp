#include<iostream>
#include<string>
#define c3 ((c1==c2&&s1.substr(0,2)==s2.substr(0,2))&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')))
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1==c2?1:0)<<((c1==c2&&s1.substr(0,2)==s2.substr(0,2))?1:0)<<(c3?1:0)<<((c3&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')))?1:0);
	return 0;
}
