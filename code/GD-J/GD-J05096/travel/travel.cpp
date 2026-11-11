#include<bits/stdc++.h>
using namespace std;
int n,m;
bool b=1;
string s,s1,x,y;
char d[6]={'A','B','C','D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.in","w",stdout);
	cin>>n>>s>>m>>s1;
	x=s.substr(0,2);
	y=s1.substr(0,2);
	if(n==m){
		cout<<1;
	}
	else{
		b=0;
		cout<<0000;
	}
	if(x==y){
		cout<<1;
	}
	else{
		b=0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(s[2]=='A'||s[2]=='B'||s[2]=='C'){
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			cout<<1;
		}
	}
	else if(b==1&&(s[2]=='D'||s[2]=='F')){
		if(s1[2]=='D'&&s1[2]=='F'){
			cout<<1;
		}
	}
	else{
		b=0;
		cout<<00;
	}
	if(s[2]=='A'&&s1[2]=='C'||s[2]=='C'&&s1[2]=='A'){
		cout<<0;
	}
	else{
		cout<<1;
	}
}
