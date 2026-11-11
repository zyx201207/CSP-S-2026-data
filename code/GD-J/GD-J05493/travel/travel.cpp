#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool a=0,b=0;
	string s,s1,s2,s3;
	cin>>s>>s1>>s2>>s3;
	if(s!=s2){
		cout<<0000;
		return 0;
	}
	cout<<1;
	if(s1[0]==s3[0]&&s1[1]==s3[1]){
		cout<<1;
		b=1;
	}
	else if(s1[0]!=s3[0]||s1[1]!=s3[1]){
		cout<<0;
		
	}
	if(b&&((s1[2]<='C'&&s3[2]<='C')||(s1[2]>='D'&&s3[2]>='D'))){
		cout<<1;
		a=1;
	}
	else{
		cout<<0;
	}
	if(a&&b&&(s1[2]+1==s3[2]||s1[2]-1==s3[2])){
		cout<<1;
	}
	else cout<<0;
	return 0;
} 
