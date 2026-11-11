#include<bits/stdc++.h>
using namespace std;
char c1[10],s1[10],c2[10],s2[10];
bool flag1=0,flag2=0,flag3=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1[1]>>c1[2];
	cin>>s1[1]>>s1[2]>>s1[3];
	cin>>c2[1]>>c2[2];
	cin>>s2[1]>>s2[2]>>s2[3];
	if(c1[1]==c2[1]&&c1[2]==c2[2]){
		cout<<1;
		flag1=1;
	}
	else{
		cout<<0;
	}
	if(s1[1]==s2[1]&&s1[2]==s2[2]&&flag1){
		cout<<1;
		flag2=1;
	}
	else{
		cout<<0;
	}
	if((s1[3]=='A'||s1[3]=='B'||s1[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s2[3]=='C')&&flag1&&flag2){
		cout<<1;
		flag3=1;
	}
	else if((s1[3]=='D'||s1[3]=='F')&&(s2[3]=='D'||s2[3]=='F')){
		cout<<1;
		flag3=1;
	}
	else{
		cout<<0;
	}
	if(abs((s1[3]-'A'+1)-(s2[3]-'A'+1))==1&&flag1&&flag2&&flag3){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
