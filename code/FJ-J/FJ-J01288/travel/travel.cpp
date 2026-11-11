#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int d=0,d2=0,d3=0,d4=0;
	long long a,a2,c,c2;
	char b3,b4;int b,b2;
    cin>>c>>a;cin>>b3;
    cin>>c2>>a2;cin>>b4;
    b=b3;b2=b4;
    if(c!=c2){
    	cout<<0<<0<<0<<0;
    	return 0;
	}
	if(c==c2)d=1;
	if(a==a2)d2=1;
	if(a!=a2){
		cout<<d<<0<<0<<0;return 0;
	}
	if(d2){
		if(b2<=67&&b<=67)d3=1;
		else if(b2>=68&&b>=68)d3=1;
		else {
			cout<<d<<d2<<0<<0;
			return 0;
		}
	}
	//int b3=b,b4=b2;
	if(b-b2==1||b2-b==1)d4=1;
	//cout<<b<<b2;
	cout<<d<<d2<<d3<<d4;
	
	return 0;
}
