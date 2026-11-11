#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	string s1,s2,s3,s4;
	cin>>a>>s1>>b>>s2;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	s3=s1[2];
	s4=s2[2];
	c=(s1[0]-'0')*10+s1[1]-'0'; 
	d=(s2[0]-'0')*10+s2[1]-'0'; 
	if(c==d) cout<<"1";
	else {
		cout<<"000";
		return 0; 
	}
	if(s3[0]<'D' && s4[0]<'D') cout<<"1";
	else if(s3[0]>='D' && s4[0]>='D') cout<<"1";
	else {
		cout<<"00";
		return 0;
	}
	if(max(s3[0],s4[0])-min(s3[0],s4[0])==1){
		cout<<"1";
	}
	else cout<<"0";
	return 0;
}
