#include<bits/stdc++.h>
using namespace std;
inline long long read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
    	if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
string ss1,ss2,ss3,ss4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ss1>>ss2>>ss3>>ss4;
	if(ss1==ss3)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	string tmp1=ss2.substr(0,2);
	string tmp2=ss4.substr(0,2);
	if(tmp1==tmp2){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(ss2[2]=='A'||ss2[2]=='B'||ss2[2]=='C'&&ss4[2]=='A'||ss4[2]=='B'||ss4[2]=='C'){
		cout<<1;
	}
	else if(ss2[2]=='D'||ss2[2]=='F'&&ss4[2]=='D'||ss4[2]=='F'){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(ss2[2]=='A'&&ss4[2]=='B'||ss2[2]=='B'&&ss4[2]=='C'||ss2[2]=='D'&&ss4[2]=='F')cout<<1;
	else if(ss4[2]=='A'&&ss2[2]=='B'||ss4[2]=='B'&&ss2[2]=='C'||ss4[2]=='D'&&ss2[2]=='F')cout<<1;
	else{
		cout<<'0';
		return 0;
	}
	return 0;
}

