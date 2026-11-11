#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int chk=1;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	if(a!=c){
		cout<<0;
		chk=0;
	}if(b[0]==d[0] and b[1]==d[1] and chk==1) cout<<1;
	if(b[0]!=d[0] or b[1]!=d[1] or chk==0){
		cout<<0;
		chk=0;
	}if((b[2]<='C' and d[2]<='C' or b[2]>='D' and b[2]>='D') and chk==1) cout<<1;
	if(b[2]<='C' and d[2]>'C' or b[2]>='D' and b[2]<'D' or chk==0){
		cout<<0;
		chk=0;
	}if(abs(b[2]-d[2])==1 and chk==1) cout<<1;
	if(abs(b[2]-d[2])!=1 or chk==0) cout<<0;
	return 0;
}
