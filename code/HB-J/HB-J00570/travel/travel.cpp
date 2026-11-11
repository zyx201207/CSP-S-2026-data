#include<bits/stdc++.h>
using namespace std;
string c[5],s[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	if(c[1]!=c[2]){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	char t=s[1][0],y=s[2][0],u=s[1][1],i=s[2][1];
	if(t==y&&u==i){
		cout<<"1";
		char e=s[1][2],r=s[2][2];
		if((e=='D'||e=='F')&&(r=='D'||r=='F')){
			cout<<"11";
			return 0;
		}
		if(((e>='A'&&e<='C')&&(r>='A'&&r<='C'))){
			cout<<"1";
			if(abs(e-r)==1) cout<<"1";
			else{
				cout<<"0";
				return 0;
			}
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		cout<<"000";
		return 0;
	}
	return 0;
}
