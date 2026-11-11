#include<bits/stdc++.h>
using namespace std;
string s,c,s1,c1;
int a[10000];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c1>>s1;
	if(c==c1){
		a[1]=1;
	}else{
		cout<<0<<" "<<0<<" "<<0<<" "<<0;
		return 0;
	}if(s1[0]==s[0]&&s[1]==s1[1]){
		a[2]=1;
	}else{
		cout<<1<<" "<<0<<" "<<0<<" "<<0;
		return 0;
	}if((s[2]=='A'||s[2]=='B'||s[2]=='C'&&s1[2]=='A'||s1[2]=='B'||s1[2]=='C'
	)||(s[2]=='D'||s[2]=='F'&&s1[2]=='D'||s1[2]=='F')){
		a[3]=1;
	}else{
		cout<<1<<" "<<1<<" "<<0<<" "<<0;
		return 0;
	}if((s[2]+1==s1[2]&&s[2]+1!='D')||(s[2]-1==s1[2]&&s1[2]!='C')){
		a[4]=1;
	}else{
		cout<<1<<" "<<1<<" "<<1<<" "<<0;
		return 0;
	}cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4];
	return 0;
} 
