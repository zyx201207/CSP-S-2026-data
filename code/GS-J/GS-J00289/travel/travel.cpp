#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,s1,s2,s3;
	cin>>s>>s1>>s2>>s3;
	if(s==s2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s3[0]&&s1[1]==s3[1]){
			cout<<1;
		}else{
			cout<<0<<0<<0;
			return 0;
		}
		if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s3[2]=='A'||s3[2]=='B'||s3[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s3[2]=='D'||s3[2]=='F'))){
			cout<<1;
		}else{
			cout<<0;
		}
		if((s1[2]=='A'&&s3[2]=='B')||(s1[2]=='B'&&s3[2]=='A')||(s1[2]=='C'&&s3[2]=='B')||(s1[2]=='B'&&s3[2]=='C')||(s1[2]=='D'&&s3[2]=='F')||(s1[2]=='F'&&s3[2]=='D')){
			cout<<1;
		}else{
			cout<<0;
	}

	return 0;
	
}
