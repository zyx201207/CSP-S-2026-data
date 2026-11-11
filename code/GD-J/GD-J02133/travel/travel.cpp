#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.in","w",stdout);
	string c,s,c1,s1;
	cin>>c>>s>>c1>>s1;
	if(c!=c1) {
		cout<<"0000";
	}
	else {
		cout<<"1";
		string p="";
		p+=s[0]+s[1];
		string q="";
		q+=s1[0]+s1[1];
		char x=s[2],y=s1[2];
		
		if(p==q) cout<<1;
		else cout<<0;
		
		if(p!=q) {
			cout<<"00";
			return 0;
		}
		else{
			if(x<'D'&&y<'D') {
				cout<<1;
			}
			else if(x>='D'&&y>='D') {
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		if((x=='D'&&y=='F')||(x=='F'&&y=='D')) {
				cout<<1;
			}
			else if(abs(x-y)==1&&x<'D'&&y<'D') {
				cout<<1;
			}
			else cout<<0;
	}
	return 0;
} 
