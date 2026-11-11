#include <bits/stdc++.h>
using namespace std;
int a,c,num1,num2;
string b,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	cin>>b;
	cin>>c;
	cin>>d;
	if(a==c) cout<<1;
	else cout<<0;
	if(b[0]+b[1]==d[0]+d[1] && a==c) cout<<1;
	else cout<<0;
	if(b[0]+b[1]==d[0]+d[1] && a==c){
		if(b[2]>='A' && b[2]<='C') num1=1;
		else num1=2;
		if(d[2]>='A' && d[2]<='C') num2=1;
		else num2=2;
		if(num1==num2) cout<<1;
		else cout<<0;
	}else cout<<0;
	if(b[0]+b[1]==d[0]+d[1] && a==c && num1==num2){
		if(b[2]=='D' && d[2]=='F') cout<<1;
		else if((b[2]+1==d[2]) || b[2]-1==d[2]) cout<<1;
		else cout<<0;
	}else cout<<0;
	return 0;
}
