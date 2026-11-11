#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	bool flag1=0;
	if(s1==s3){
		cout<<1;
		flag1=1;
	}
	else cout<<0;
	bool flag=0;
	if(flag1&&s2.substr(0,2)==s4.substr(0,2)){
		cout<<1;
		flag=1;
	}
	else cout<<0;
	bool flag2=0;
	if(flag&&((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s4[2]=='A'||s4[2]=='B'||s4[2]=='C'))||((s2[2]=='D'||s2[2]=='F')&&(s4[2]=='D'||s4[2]=='F'))){
		cout<<1;
		flag2=1;
	} 
	else{
		cout<<0;
	}
	if(flag2&&((s2[2]=='A'&&s4[2]=='B')||(s2[2]=='B'&&s4[2]=='C')||(s2[2]=='D'&&s4[2]=='F'))){
		cout<<1;
	}
	else{
		cout<<0;
	}
    return 0;
}
