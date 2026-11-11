#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int c1,c2;
	bool f1=0,f2=0,f3=0,f4=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		f1=1;
	}
	if(f1==0){
		cout<<"0";
	}
	if(f1==1&&(s1[0]==s2[0]&&s1[1]==s2[1])){
		cout<<"1";
		f2=1;
	}
	if(f2==0){
		cout<<"0";
	}
	if(f2==1&&f1==1&&(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]=='D'||s1[2]=='F'&&s2[2]=='D'||s2[2]=='F')){
		cout<<"1";
		f3=1;
	}
	if(f3==0){
		cout<<"0";
	}
	if(f1==1&&f2==1&&f3==1&&(s1[2]==s2[2]-1||s1[2]==s2[2]+1)){
		cout<<"1";
		f4=1;
	}
	if(f4==0){
		cout<<"0";
	}
	return 0;
}
