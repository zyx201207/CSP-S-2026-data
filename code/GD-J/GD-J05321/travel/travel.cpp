#include<bits/stdc++.h>
using namespace std;
bool f=false,f1=false,f2=false;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		f=true;
	}
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]&&f==true){
		cout<<1;
		f1=true;
	}
	else cout<<0;
	if(d[2]>'C'&&b[2]>'C'&&b!=d&&f1==true)cout<<1,f2=true;
	else if(d[2]<='C'&&b[2]<='C'&&b!=d&&f1==true)cout<<1,f2=true;
	else cout<<0;
	if(abs(d[2]-b[2])==1&&f2==true)cout<<1;
	else cout<<0;
}
