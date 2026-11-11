#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,s,b,t;
	cin>>a>>s>>b>>t;
	if(a!=b){
		cout<<"0000";
	}
	else{
		cout<<1;
		if(s[0]==t[0]&&s[1]==t[1]){
			cout<<1;
			if(s[2]=='D'){
				if(t[2]=='F'){
					cout<<11;
				}
				else{
					cout<<"00";
				}
			}
			else if(s[2]=='F'){
				if(t[2]=='D'){
					cout<<11;
				}
				else{
					cout<<"00";
				}
			}
			else if(s[2]=='C'){
				if(t[2]=='B'){
					cout<<11;
				}
				else if(t[2]=='A'){
					cout<<10;
				}
				else{
					cout<<"00";
				}
			}
			else if(s[2]=='B'){
				if(t[2]=='A'||t[2]=='C'){
					cout<<11;
				}
				else{
					cout<<"00";
				}
			}
			else if(s[2]=='A'){
				if(t[2]=='B'){
					cout<<11;
				}
				else if(t[2]=='C'){
					cout<<10;
				}
				else{
					cout<<"00";
				}
			}
		}
		else{
			cout<<"000";
		}
	}
	
	
	
	return 0;
}