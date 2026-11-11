//GZ-J00702 遵义市第十九中学 毛文颢
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	bool flag1=false,flag2=false,flag3=false;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		flag1=true;
	}
	else cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&flag1){
		cout<<1;
		flag2=true;
	}
	else cout<<0;
	if((((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))&&flag2){
		cout<<1;
		flag3=true;
	}
	else cout<<0;
	if((((s1[2]>='A'&&s1[2]<='C')&&(s2[2]==s1[2]+1||s2[2]==s1[2]+1))||((s1[2]=='D'&&s1[2]=='F')||s1[2]=='F'&&s2[2]=='D'))&&flag3) cout<<1;
	else cout<<0;
	
	return 0;
}
