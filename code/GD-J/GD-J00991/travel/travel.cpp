#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s,s1,s2,s3;
	cin>>s>>s1>>s2>>s3;
	if(s!=s2){
		cout<<0;
	}
	else{
		cout<<1;
	}
	if((s!=s2)||(s1[1]!=s3[1])){
		cout<<0;
	}
	else{
		cout<<1;
	}
	if((s!=s2)||(s1[1]!=s3[1])||(s1[2]<='C'&&s3[2]>='D')||(s1[2]>='D'&&s3[2]<='C')){
		cout<<0;
	}
	else{
		cout<<1;
	}
	if(s!=s2||s1[1]!=s3[1]||(s1[2]<='C'&&s3[2]>='D')||(s1[2]>='D'&&s3[2]<='C')||(s1[2]+1!=s3[2]&&s1[2]-1!=s3[2])){
		cout<<0;
	}
	else{
		cout<<1;
	}
	return 0;
}
