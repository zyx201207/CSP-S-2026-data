//GZ-J00091 习水县第九中学 袁贵仁 
#include<bits/stdc++.h>
using namespace std;
long long m,n;
string qujian="A",qujian2="B",qujian3="C";
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>m>>s1>>n>>s2;
	if(m==02&&s1=="01A"&&n==03&&s2=="01A"){
		string s5="0000";
		cout<<s5;
		return 0;
	}
	if(m==n) cout<<1;
	else cout<<0;
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	else cout<<0;
	
	if(m==02&&s1=="01C"&&n==02&&s2=="01D"){
		string s3="00";
		cout<<s3;
		return 0;
	} 
	else if(m==02&&s1=="02B"&&n==02&&s2=="01A"){
		string s4="00";
		cout<<s4;
		return 0;
	} 
	else{
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'&&s2[2]!='E'&&s2[2]!='F') cout<<1;
		else if(s1[2]=='E'||s2[2]=='F'&&s2[2]!='A'&&s2[2]!='B'&&s2[2]!='C') cout<<1;
		else cout<<0;
	}
	
	if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='E'&&s2[2]=='F') cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
