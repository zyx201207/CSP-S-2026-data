#include<bits/stdc++.h>
using namespace std;
string s1,s2,ss1,ss2;
int g_n(string s){
	return (s[0]-'0')*10+(s[1]-'0');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>ss1>>s2>>ss2;
	int n1=g_n(s1),n2=g_n(s2),nn1=g_n(ss1),nn2=g_n(ss2);
	char c1=ss1[2],c2=ss2[2];
	if(n1==n2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(nn1==nn2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((c1<='C'&&c2<='C')||('E'<=c1&&'E'<=c2)){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(c2-c1)==1){
		cout<<1;
	}else{
		cout<<0;
		return 0;
	}
	return 0;
}
