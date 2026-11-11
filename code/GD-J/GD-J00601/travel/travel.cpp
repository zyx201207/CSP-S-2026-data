#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3)cout<<"0000";
	else if(s2[0]!=s4[0]||s2[1]!=s4[1])cout<<"1000";
	else if((s2[2]=='F'&&s4[4]!='D')||(s2[2]=='D'&&s4[2]!='F')||(s2[2]!='F'&&s4[2]=='D')||(s2[2]!='D'&&s4[2]=='F'))cout<<"1100";
	else if((s2[2]+1!=s4[2])&&(s2[2]-1!=s4[2]))cout<<"1110";
	else cout<<"1111";
	return 0;
}
