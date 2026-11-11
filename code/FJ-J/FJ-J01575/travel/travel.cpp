#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
char x,y;
int u=0,v=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
	cout<<"0000";
	}
	else{
		cout<<"1";
		u=b[0]-'0';
		v=d[0]-'0';
		u=u*10+b[1]-'0';
		v=v*10+d[1]-'0';
		x=b[2];
		y=d[2];
		if(u!=v){
		cout<<"000";
		}
		else{
			cout<<"1";
		if(((x>='A'&&x<='C')&&(y>='A'&&y<='C'))||((x>='D'&&x<='F')&&(y>='D'&&y<='F'))){
			cout<<"1";
			if(abs(x-y)==1){
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
		else{
			cout<<"00";
		}
		}
	}
	return 0;
}
