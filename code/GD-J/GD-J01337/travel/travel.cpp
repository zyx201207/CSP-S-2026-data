#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int turn(string s){
	return s[0]*10+s[1];
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>a>>b>>c>>d;
	int e=turn(a);
	int f=turn(b);
	int g=turn(c);
	int h=turn(d);
	char x=b[2];
	char y=d[2];
	if(e!=g)cout<<"0000";
	else{
		cout<<"1";
		if(f==h){
			cout<<"1";
			if(x>='A'&&x<='C'&&y>='A'&&y<='C')cout<<"1";
			else if(x>='D'&&x<='E'&&y>='D'&&y<='E')cout<<"1";
			else cout<<"0";
		}
		else cout<<"00";
		if(f==h&&abs(x-y)==1&&((y!='C'&&x!='D')&&(x!='C'&&y!='D')))cout<<"1";
		else if(x==y&&abs(f-h)==1)cout<<"1";
		else cout<<"0";
	}
	return 0;
} 
