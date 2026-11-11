#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	bool ok=1;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<0;
		ok=0;
	}
	else{
		cout<<1;
	}
	if(b[0]==d[0]&&b[1]==d[1]&&ok){
		cout<<1;
	}
	else{
		cout<<0;
		ok=0;
	}
	if((b[2]<='C'&&d[2]>='D')||(b[2]>='D'&&d[2]<='C')||!ok){
		cout<<0;
		ok=0;
	}
	else{
		cout<<1;
	}
	if(((b[2]>='D'&&d[2]>='D')||(b[2]<='C'&&d[2]<='C'&&abs(b[2]-d[2])==1))&&ok) cout<<1;
	else cout<<0;
	return 0;
}
