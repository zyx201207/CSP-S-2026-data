#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}
	int s1_part,s2_part;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')s1_part=0;
	else s1_part=1;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')s2_part=0;
	else s2_part=1;
	if(s1_part!=s2_part){
		cout<<"1100";
		return 0;
	}
	char s1_a,s2_a;
	s1_a=s1[2];
	s2_a=s2[2];
	if(s1_a-1==s2_a||s1_a+1==s2_a)cout<<"1111";
	else cout<<"1110";	

	return 0;}

