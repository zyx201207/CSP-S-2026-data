#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int is1=s1[2],is2=s2[2];
	if(c1[0]!=c2[0] || c1[1]!=c2[1])
		cout<<"0000";
	else if(s1[0]!=s2[0] || s1[1]!=s2[1])
		cout<<"1000";
	else if(s1[2]<='C' && s2[2]>='D')
		cout<<"1100";
	else if(s2[2]<='C' && s1[2]>='D')
		cout<<"1100";
	else if(abs(is1-is2) >= 2)
		cout<<"1110";
	else  cout<<"1111";
	return 0;
} 
