#include <iostream>
#include <string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	int a=(s1[0]-'0')*10+(s1[1]-'0'),b=(s2[0]-'0')*10+(s2[1]-'0'),c=s1[2]-s2[2];
	if(a==b) cout<<1;
	else cout<<0;
	
	if(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')) && a==b) cout<<1;
	else cout<<0;
	
	if(((abs(a-b)==1 || abs(c)==1) && abs(a-b)!=abs(c)) && s1[2]+s2[2]!=135) cout<<1;
	else cout<<0;
	return 0;
}
