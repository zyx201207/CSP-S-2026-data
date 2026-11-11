#include<bits/stdc++.h>
using namespace std;
long long n;
string s,k,se,ke;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>k>>se>>ke;
	if(s==se)cout<<"1";
	else {
		cout<<"0000";
		return 0;
		}
	if(k[0]==ke[0]&&k[1]==ke[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}	
	if(((k[2]=='A'||k[2]=='B'||k[2]=='C')&&(ke[2]=='A'||ke[2]=='B'||ke[2]=='C'))||((k[2]=='F'||k[2]=='D')&&(ke[2]=='F'||ke[2]=='D'))){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
		}
		if((k[2]=='A'&&ke[2]=='B')||(k[2]=='B'&&ke[2]=='A')||(k[2]=='B'&&ke[2]=='C')||(k[2]=='C'&&ke[2]=='B')||(k[2]=='D'&&ke[2]=='F')||(k[2]=='D'&&ke[2]=='F')){
			cout<<"1";
			}
			else{
				cout<<"0";
				}
	return 0;
}
