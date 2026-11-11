#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string n;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string  m;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&((s1[2]>='D'&&s2[2]>='D')||(s1[2]<'D'&&s2[2]<'D'))&&((s1[2]==s2[2]+1)||(s1[2]==s2[2]-1))){
		m="1111";
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&((s1[2]>='D'&&s2[2]>='D')||(s1[2]<'D'&&s2[2]<'D'))&&((s1[2]!=s2[2]+1)||(s1[2]!=s2[2]-1))){
		m="1110";
	}if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&((s1[2]>='D'&&s2[2]<'D')||(s1[2]<'D'&&s2[2]>='D'))){
		m="1100";
	}if(c1==c2&&s1[0]==s2[0]&&s1[1]!=s2[1]){
		m="1000";
	}if(c1!=c2){
		m="0000";
	}
	cout<<m;
	return 0;
}
