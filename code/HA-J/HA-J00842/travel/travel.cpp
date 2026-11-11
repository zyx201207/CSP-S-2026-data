#include<bits/stdc++.h>
using namespace std;
string c,s,a,b;
char q,w;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>a>>b;
	if(c==a){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(s[1]==b[1]){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(s[1]==b[1]){
		if('F'>=s[2]>='D' && 'F'>=b[2]>='D' || 'C'>=s[2]>='A' && 'C'>=b[2]>='A'){
			cout<<'1';
		}else{
			cout<<'0';
		}
	}
	if(s[2]+1==b[2] || s[2]-1==b[2] && b[2]+1==s[2] || b[2]-1==s[2]){
		cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
}
