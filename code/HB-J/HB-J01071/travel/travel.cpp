#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int a1=0,b1=0,c=0,d1=0;
	if(c1==c2) a1=1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[1]==s2[1]&&s1[0]==s2[0]) b1=1;
	else{
		cout<<"1000";
		return 0;
	}
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C') c=1;
	else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F') c=2;
	else{
		cout<<"1100";
		return 0;
	}
	if(c==1){
		if(s1[2]+1==s2[2]||s1[2]-1==s2[2]) cout<<"1111";
	}else if(c==2) cout<<"1111";
	else cout<<"1110";
	return 0;
}
