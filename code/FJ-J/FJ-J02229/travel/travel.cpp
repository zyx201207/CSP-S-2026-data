#include<bits/stdc++.h>
using namespace std;
string s[4];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<4;i++){
		cin>>s[i];
	}
	if(s[0][0]!=s[2][0]||s[0][1]!=s[2][1]){
		cout<<"0000";
		return 0;
	}else cout<<1;
	if(s[1][0]!=s[3][0]||s[1][1]!=s[3][1]){
		cout<<"000";
		return 0;
	}else cout<<1;
	int a1,a2;
	if(s[1][2]=='A'||s[1][2]=='B'||s[1][2]=='C')a1=1;
	else a1=0;
	if(s[3][2]=='A'||s[3][2]=='B'||s[3][2]=='C')a2=1;
	else a2=0;
	if(a1!=a2){
		cout<<"00";
		return 0;
	}else cout<<1;
	if(a1==0)cout<<1;
	else if(abs(int(s[3][2])-s[1][2])<=1)cout<<1;
	else cout<<0;
	return 0;
}
