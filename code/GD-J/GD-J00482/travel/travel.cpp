#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s,t;
	cin>>a>>s>>b>>t;
	if(a!=b){
		cout<<"0000";
	}else{
		cout<<1;
		int x=s[0]-'0'+s[1]-'0';
		int y=t[0]-'0'+t[1]-'0';
		if(x!=y){
			cout<<"000";
		}else{
			cout<<1;
			if((s[2]<='C'&&t[2]<='C')||(s[2]+t[2]=='D'+'F')){
				cout<<1;
				if(s[2]+t[2]=='A'+'B'||s[2]+t[2]=='B'+'C'||s[2]+t[2]=='D'+'F'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}
	}
	return 0;
}
