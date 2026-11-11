#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char e,f;
string s,s1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>s1;
	for(int i=0;i<s.size()-1;i++){
		c=c*10+(s[i]-48);
	}
	for(int i=0;i<s1.size()-1;i++){
		d=d*10+(s1[i]-48);
	}
	e=s[s.size()-1];
	f=s1[s1.size()-1];
	if(a==b)cout<<1;
	else cout<<0;
	if(a==b&&c==d)cout<<1;
	else cout<<0;
	if(a==b&&c==d&&(e<='C'&&f<='C')||(e>'C'&&f>'C'))cout<<1;
	else cout<<0;
	if(a==b&&c==d&&((e<='C'&&f<='C')||(e>'C'&&f>'C'))&&(e+1==f||f+1==e))cout<<1;
	else cout<<0;
	return 0;
}