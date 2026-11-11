#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	string s;
	string a;
	cin>>n>>s>>m>>a;
	if(n!=m){
		cout<<"0000";
	}
	else{
		if(a[0]==s[0]&&a[1]==s[1]){
			if(a[2]=='A'||a[2]=='B'||a[2]=='C'&&s[2]=='A'||s[2]=='B'||s[2]=='C'&&a[2]!='D'&&a[2]!='F'&&s[2]!='D'&&s[2]!='F'){
				if(a[2]=='A'&&s[2]=='B'||a[2]=='B'&&s[2]=='C'||s[2]=='A'&&a[2]=='B'||s[2]=='B'&&a[2]=='C'){
					cout<<"1111";
				}       
				else{
					cout<<"1110";
				}
			}
			else{
				if(a[2]=='D'&&s[2]=='F'||a[2]=='F'&&s[2]=='D'){
					cout<<"1111";
				}
				else{
					cout<<"1100";
				}
			}
		}
		else{
			cout<<"1000";
		}
	}
	return 0;
}
