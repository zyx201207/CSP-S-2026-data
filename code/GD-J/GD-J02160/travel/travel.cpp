#include<bits/stdc++.h>
using namespace std;
int r,x;
string rs,xs;
int num(string s){
	return (s[0]-'0')*10+s[1]-'0';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>rs>>x>>xs;
	if(r==x){
		cout<<'1';
		if(num(rs)==num(xs)){
			cout<<'1';
			if((rs[2]>'C'&&xs[2]>'C')||(rs[2]<='C'&&xs[2]<='C')){
				cout<<'1';
				if(abs(rs[2]-xs[2])==1){
					cout<<'1';
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
