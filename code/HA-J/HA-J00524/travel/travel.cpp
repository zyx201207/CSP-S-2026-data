#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","l",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool f1=0,f2=0,f3=0,f4=0;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		f1=1;
	}
	else{
		cout<<0;
	}
	if(f1==1&&b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
		f2=1;
	}
	else{
		cout<<0;
	}
	if(f2==1&&((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')))){
		cout<<1;
		f3=1;
	}
	else{
		cout<<0;
	}
	if(f3==1){
		if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
			cout<<1;
		}
		else if(char(b[2]+1)==char(d[2])||char(b[2]-1)==char(d[2])){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else cout<<0;
	return 0;
}
