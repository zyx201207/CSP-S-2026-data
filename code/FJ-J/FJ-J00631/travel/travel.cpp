#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	io;
	cin>>c1>>s1>>c2>>s2;
	int flag1=1;
	if(c1==c2) cout<<1;
	else{
		cout<<0;
		flag1=0;
	} 
	int a[3],b[3];
	char ch1,ch2;
	int flag2=1,flag3=0;
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i]) flag2=0;
	}
	if(flag2&&flag1){
		cout<<1;
	} 
	else{
		cout<<0;
		flag1=flag2=0;
	} 
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&flag2){
			cout<<1;
			flag3=1;
		} 
		else cout<<0;
	}
	else{
		if((s2[2]=='D'||s2[2]=='F')&&flag2){
			cout<<1;
			flag3=1;
		} 
		else cout<<0;
	}
	if(flag3&&flag2&&flag1){
		if(abs(s2[2]-s1[2])==1) cout<<1;
		else cout<<0; 
	}
	else cout<<0;
	return 0;
}
