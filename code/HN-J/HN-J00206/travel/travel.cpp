#include<bits/stdc++.h>
using namespace std;
#define int long long
string s,s2,s3,s4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s>>s2>>s3>>s4;
	if(s==s3){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s==s3&&s2[0]==s4[0]&&s2[1]==s4[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s==s3&&s2[0]==s4[0]&&s2[1]==s4[1]){
		if((s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C')||(s2[2]=='D'&&s4[2]=='F')||(s2[2]=='F'&&s4[2]=='D')){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(s==s3&&s2[0]==s4[0]&&s2[1]==s4[1]){
		if((s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C')||(s2[2]=='D'&&s4[2]=='F')||(s2[2]=='F'&&s4[2]=='D')){
			if((s2[2]=='D'&&s4[2]=='F')||(s2[2]=='F'&&s4[2]=='D')||s4[2]=='B'||s2[2]=='B'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}
