#include<bits/stdc++.h >
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool f=0,f1=0,f2=0;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		f2=1;
	}
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]&&f2){
		cout<<1;
		f1=1;
	}
	else cout<<0;
	if(f2&&((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'))){
		cout<<1;
		f=1;
	}
	else cout<<0;
	if(f2&&f&&f1&&abs(b[2]-d[2])==1)cout<<1;
	else cout<<0;
	return 0;
}
