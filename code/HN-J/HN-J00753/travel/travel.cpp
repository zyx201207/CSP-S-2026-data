#include <bits/stdc++.h>
using namespace std;
long long main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else {
		cout<<0<<0<<0<<0;
		return 0;
	}
	long long pb=0,pd=0;
	pb+=(b[0]-'0')*10+(b[1]-'0');
	pd+=(d[0]-'0')*10+(d[1]-'0');
	if(pd==pb) cout<<1;
	else {
		cout<<0<<0<<0;
		return 0;
	}
	char B=b[2],D=d[2];
	if(B>D) swap(B,D);
	if((B=='A'&&(D=='C'||D=='B'))||(B=='B'&&D=='C')||(B=='D'||D=='F'))cout<<1;
	else {
		cout<<0<<0;
		return 0;
	}
	if((B=='A'&&D=='B')||(B=='B'&&D=='C')||(B=='D'||D=='F'))cout<<1;
	else {
		cout<<0;
	}
	return 0;
}  
