#include <bits/stdc++.h>
using namespace std;
string n,m,c,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>n>>m>>c>>s;
	if(n!=c){
		cout<<"0000";
	}else{
		cout<<"1";
		string tm="",ts="";
		tm+=m[0]+m[1];
		ts+=s[0]+s[1];
		if(tm!=ts){
			cout<<"000";
		}else{
			cout<<"1";
			if(m[2]<='C'&&s[2]<='C'||s[2]>='D'&&m[2]>='D'){
				cout<<"1";
			}else{
				cout<<"0";
			}
			if((m[2]<='C'&&s[2]<='C'||s[2]>='D'&&m[2]>='D')&&(abs(m[2]-s[2])==1)){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
	}
	
	return 0;
}
