#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string s,a;
	cin>>n>>s>>m>>a;
	if(n==m){
		if(s[0]==a[0]&&s[1]==a[1]){
			if((s[2]>='A'&&s[2]<='C')&&(a[2]>='A'&&a[2]<='C')){
				if((s[2]=='B'&&a[2]=='A')||(s[2]=='A'&&a[2]=='B')){
					cout<<"1111";
				}
				else if((s[2]=='B'&&a[2]=='C')||(s[2]=='C'&&a[2]=='B')){
					cout<<"1111";
				}
			}
			else if((s[2]=='D'&&a[2]=='F')||(s[2]=='F'&&a[2]=='D')){
				cout<<"1111";
			}
			else if((s[2]>='A'&&s[2]<='C')&&(a[2]=='D'||a[2]=='F')){
				cout<<"1100";
			}
			else if((a[2]>='A'&&a[2]<='C')&&(s[2]=='D'||s[2]=='F')){
				cout<<"1100";
			}
			if((a[2]=='A'&&s[2]=='C')||(s[2]=='A'&&a[2]=='C')){
				cout<<"1110";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
