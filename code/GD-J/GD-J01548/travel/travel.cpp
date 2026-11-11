#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int zh(char s){
	if(s<'D') return 1;
	else return 0; 
} 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) cout<<'1';
	else cout<<'0';
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1]) cout<<1;
	else cout<<0;
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1]&&zh(s2[2])==zh(s4[2])) cout<<1;
	else cout<<0;
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1]&&zh(s2[2])==zh(s4[2])&&abs(s2[2]-s4[2])==1) cout<<1;
	else cout<<0;
}
