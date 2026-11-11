#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int flag=0,flag1=0,flag2=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		cout<<1;flag2=1;
	}
	else cout<<0;
	if(flag2==1 && s1[0]==s2[0] && s1[1]==s2[1]) {
		cout<<1;flag1=1;
	}
	else cout<<0;
	if(flag1==1 && (s1[2]=='A' || s1[2]=='B' || s1[2]=='C') && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C')){
		cout<<1;flag=1;
	} 
	else if(flag==1 && (s1[2]=='D' || s1[2]=='F') && (s2[2]=='D' || s2[2]=='F')){
		cout<<1;flag=1;
	} 
	else cout<<0;
	if(flag==1 && abs(s1[2]-s2[2])==1) cout<<1;
	else cout<<0;
}
