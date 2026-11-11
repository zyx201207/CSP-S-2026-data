#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,c2,s1,s2;
bool f(){
	char x=s1[2];
	char y=s2[2];
	if((x!='D'&&x!='F')&&(y=='D'||y=='F')){
		return 1;
	}
	else if((y!='D'&&y!='F')&&(x=='D'||x=='F')){
		return 1;
	}
	return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
	}
	else if(f()){
		cout<<"1100";
	}
	else if((s1[2]=='A'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='C')){
		cout<<"1110";
	}
	else{
		cout<<"1111";
	}
	return 0;
}
