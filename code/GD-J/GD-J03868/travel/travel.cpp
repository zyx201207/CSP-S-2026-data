#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",str);
	freopen("travel.out","w",str);
	int n,m;
	string s1,s2;
	cin>>n>>s1>>m>>s2;
	if(n==m){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s2[2]=='A'&&s1[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s2[2]=='B'&&s1[2]=='C')||(s1[2]=='A'&&s2[2]=='C')||(s2[2]=='A'&&s1[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s2[2]=='A'&&s1[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s2[2]=='B'&&s1[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
