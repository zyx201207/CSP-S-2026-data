#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	bool flag=0,flag1=0,flag2=0;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
		flag2=1;
	}
	else cout<<0;
	if(s2[0]+s2[1]==s4[0]+s4[1]&&flag2==1){
		flag1=1;
		cout<<1;
	}
	else cout<<0;
	if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s4[2]=='A'||s4[2]=='B'||s4[2]=='C')&&flag1==1){
		flag=1;
		cout<<1;
	}else if((s2[2]=='D'||s2[2]=='F')&&(s4[2]=='D'||s4[2]=='F')){
		flag=1;
		cout<<1;
	}else cout<<0;
	if(flag==1&&abs(int(s2[2])-int(s4[2]))==1){
		cout<<1;
	}else cout<<0;
	return 0;
}
