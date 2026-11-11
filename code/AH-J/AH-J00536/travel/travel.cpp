#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,s1,s2,s3;
	cin>>s>>s1>>s2>>s3;
	int sll=s.length()-1;
	bool f=1,f1=1;
	int i=1;
	for(i=1;i<=sll;i++){
		if(s[i]!=s2[i])f=0;
		if(s1[i]!=s3[i])f1=0;
	}	
	int a,b;
	if(s1[i-1]=='A')a=1;
	if(s1[i-1]=='B')a=2;
	if(s1[i-1]=='C')a=3;
	if(s3[i-1]=='A')b=1;
	if(s3[i-1]=='B')b=2;
	if(s3[i-1]=='C')b=3;
	if(f==1)cout<<1;		
	else cout<<0;
	if(f==1&&f1==1)cout<<1;
	else cout<<0;	
	if(f==1&&f1==1&&s1[i-1]=='F'&&s3[i-1]=='D'){
		cout<<1<<1;
	}else if(f==1&&f1==1&&s1[i-1]=='D'&&s3[i-1]=='F'){
		cout<<1<<1;
	}else if(f==1&&f1==1&&a<=3&&b<=3){
		cout<<1;
		if(s1[i-1]+1==s3[i-1]){
			cout<<1;
		}else if(s1[i-1]-1==s3[i-1]){
			cout<<1;
		}else cout<<0;
	}else cout<<0<<0;
	return 0;
}
