#include<iostream>
using namespace std;
string s1,s2,s3,s4;
bool flag,s_2,s_4;
int main(){
freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)
	cout<<1;
	else cout<<0;
	if(s1==s3&&s2[0]+s2[1]==s4[0]+s4[1]){
		cout<<1;
		flag=1;
	}else cout<<0;
	if(flag&&(s2[2]=='A'&&s4[2]=='B'||s2[2]=='B'&&s4[2]=='A'||s2[2]=='B'&&s4[2]=='C'||s2[2]=='C'&&s4[2]=='B'||s2[2]=='D'&&s4[2]=='F'||s2[2]=='F'&&s4[2]=='D'||s2[2]=='A'&&s4[2]=='C'||s2[2]=='C'&&s4[2]=='A')){
		cout<<1;
	}
	else cout<<0;
	
	if(flag&&(s2[2]=='F'&&s4[2]=='D'||s2[2]=='D'&&s4[2]=='F'||s2[2]=='C'&&s4[2]=='B'||s2[2]=='B'&&s4[2]=='C'||s2[2]=='A'&&s4[2]=='B'||s2[2]=='B'&&s4[2]=='A'))cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//coder by:chen
