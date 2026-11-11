#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>s>>m>>t;
	if(n!=m){
		cout<<"0000";
		return 0;
	}
	if(s[0]!=t[0]||s[1]!=t[1]){
		cout<<"1000";
		return 0;
	}
	if(s[2]=='A'){
		if(t[2]!='B'&&t[2]!='C'){
			cout<<"1100";
			return 0;
		}else if(t[2]!='B'){
			cout<<"1110";
			return 0;
		}else{
			cout<<"1111";
			return 0;
		}
	}
	if(s[2]=='B'){
		if(t[2]!='A'&&t[2]!='C'){
			cout<<"1100";
			return 0;
		}else{
			cout<<"1111";
			return 0;
		}
	}
	if(s[2]=='C'){
		if(t[2]!='B'&&t[2]!='A'){
			cout<<"1100";
			return 0;
		}else if(t[2]!='B'){
			cout<<"1110";
			return 0;
		}else{
			cout<<"1111";
			return 0;
		}
	}
	if(s[2]=='D'){
		if(t[2]!='F'){
			cout<<"1100";
			return 0;
		}else{
			cout<<"1111";
			return 0;
		}
	}
	if(s[2]=='F'){
		if(t[2]!='D'){
			cout<<"1100";
			return 0;
		}else{
			cout<<"1111";
			return 0;
		}
	}
}

















