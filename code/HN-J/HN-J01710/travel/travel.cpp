#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+5;
string s1,s3,s2,s4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	int p=0;
	if(s1==s3){
		cout<<1;
	}
	else{
		cout<<0;
		p=1;
	}
	if(p){
		cout<<0<<0<<0;
		return 0;
	}
	int flag=0;
	if(s2[0]==s4[0]&&s2[1]==s4[1]){
		cout<<1;
	}
	else{
		cout<<0;
		flag=1;
	}
	int vis=0;
	if(flag){
		cout<<0;
	}
	else if((s2[2]=='D'||s2[2]=='E')&&(s4[2]=='D'||s4[2]=='E')){
		cout<<1;
	}
	else if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s4[2]=='A'||s4[2]=='B'||s4[2]=='C')){
		cout<<1;
	}
	else{
		cout<<0;
		vis=1;
	}
	if(flag||vis){
		cout<<0;
	}
	else if((s2[2]=='E'&&s4[2]=='D')||(s2[2]=='D'||s4[2]=='E')){
		cout<<1;
	}
	else{
		int a=(int)s2[2];
		int b=(int)s4[2];
		if(max(a,b)-min(a,b)==1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
