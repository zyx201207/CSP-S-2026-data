#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s1,s2;
	cin>>a>>s1>>b>>s2;
	char a1=s1[2],b1=s2[2];
	if(a==b && a!=1 &&a!=16){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1])cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	if((a1<='C'&&b1<='C')||(a1>='D'&&b1>='D')&&a1!=b1){
		cout<<1;
	}else {
		cout<<"00";
		return 0;
	}
	if(a1+1==b1||a1-1==b1)cout<<1;
	else{
		cout<<"0";
		return 0;
	}
	return 0;
}
