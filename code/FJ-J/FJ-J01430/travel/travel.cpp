#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,b,s2,ss2;
	string s,ss;
	cin>>a>>s>>b>>ss;
//	cout<<a<<"|"<<s<<"|"<<b<<"|"<<ss<<"\n";
	if(a==b){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a==b)
	{
		if(s[0]==ss[0]&&s[1]==ss[1]){
			if(s[2]!=ss[2]){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	if(a==b)
	{
		if(s[2]=='A'||s[2]=='B'||s[2]=='C') s2=1;
		else s2=0;
		if(ss[2]=='A'||ss[2]=='B'||ss[2]=='C') ss2=1;
		else ss2=0;
		if(s2==ss2) cout<<"1";
		else cout<<"0";
	}else{
		cout<<0;
	}
	if(a==b&&s2==ss2)
	{
		if((s[2]=='A'&&ss2=='B')||(ss[2]=='A'&&s2=='B')){
			cout<<"1";
		}else if((s[2]=='C'&&ss2=='B')||(ss[2]=='C'&&s2=='B')){
			cout<<"1";
		}else if((s[2]=='F'&&ss2=='D')||(ss[2]=='F'&&s2=='D')){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	return 0;
}