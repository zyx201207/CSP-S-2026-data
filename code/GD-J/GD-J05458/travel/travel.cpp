#include <bits/stdc++.h>
using namespace std;
string s,ss;
int a,b;
int cnt;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>ss;
	if(a==b){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	
	if(s[0]==ss[0]&&s[1]==ss[1]&&s[2]!=ss[2]&&a==b){
		cout<<'1';
	}	
	else{
		cout<<'0';
	}
	                                                                     
	if(s[1]==ss[1]&&s[0]==ss[0]&&s[2]>='A'&&s[2]<='C'&&ss[2]>='A'&&ss[2]<='C'&&s[2]!=ss[2]&&a==b){
		cout<<'1';
		cnt=1;
	}
	else if(s[1]==ss[1]&&s[0]==ss[0]&&ss[2]>='D'&&ss[2]<='F'&&s[2]>='D'&&s[2]<='F'&&s[2]!=ss[2]&&a==b){
		cout<<'1';
			cnt=1;
	}
	else{
		cout<<'0';
	}

	if(cnt==1&&s[2]==ss[2]-1){
		cout<<'1';
	}
	else if(cnt==1&&ss[2]==s[2]-1){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	return 0;
} 
