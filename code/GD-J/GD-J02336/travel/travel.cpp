#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	bool c=false;
	if(cr==cx){
		cout<<1;
		c=true;
	}else cout<<0;
	
	bool s=false;
	if(c&&sr[0]==sx[0]&&sr[1]==sx[1]){
		cout<<1;
		s=true;
	}else cout<<0;
	if(s){
		char x=sr[2],y=sx[2];
		if((x>='A'&&x<='C'&&y>='A'&&y<='C')||(x>='D'&&x<='F'&&y>='D'&&y>='F')){
			cout<<1;
			if(x>='A'&&x<='C'&&y>='A'&&y<='C'&&abs(x-y)==1||x=='D'&&y=='F'||x=='F'&&y=='D'){
				cout<<1;
			}
			else cout<<0;
		}else cout<<0<<0;
	}else cout<<0<<0;
	
	return 0;
}
