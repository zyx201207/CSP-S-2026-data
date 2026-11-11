#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool a1=0,a2=0,a3=0,a4=0;
	if(a==c){
		cout<<1;
		a1=1;	
	} 
	if(a1==0) cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]&&a1==1){
		cout<<1;
		a2=1;
	}
	if(a2==0) cout<<0;
	if(d[2]<='C'&&b[2]<='C'||d[2]>'C'&&b[2]>'C'){
		if(a1==1&&a2==1){
			cout<<1;
			a3=1;
		}
	}
	if(a3==0) cout<<0;
	if(abs(b[2]-'A'-(d[2]-'A'))==1){
		if(a1==1&&a2==1&&a3==1){
			cout<<1;
			a4=1;
		}
	}
	if(a4==0) cout<<0;
	return 0;
}
