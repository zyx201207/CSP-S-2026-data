#include<bits/stdc++.h>
using namespace std;
string s,s1,s2;
long long a[10],b[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		a[i]=s[i]-'0';
	}
	cin>>s1;
	cin>>s;
	for(int i=0;i<s.size();++i){
		b[i]=s[i]-'0';
	}
	cin>>s2;
	if(a[0]==b[0] && a[1]==b[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if((a[0]==b[0] && a[1]==b[1]) && (s1[0]==s2[0] && s1[1]==s2[1])){
		cout<<1;	
	}else{
		cout<<0;
	}
	if((a[0]==b[0] && a[1]==b[1]) && (s1[0]==s2[0] && s1[1]==s2[1]) && ((s1[2]=='A' || s1[2]=='B' || s1[2]=='C') && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C')) || ((s1[2]=='D' || s1[2]=='F') && (s2[2]=='D' || s2[2]=='F'))){
		cout<<1;
	}else{
		cout<<0;
	}
	if((a[0]==b[0] && a[1]==b[1]) && (s1[0]==s2[0] && s1[1]==s2[1]) && ((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='A')) || ((s1[2]=='C' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C')) || ((s1[2]=='F' && s2[2]=='D') || (s1[2]=='D' && s2[2]=='F'))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
