#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,pai1,pai2;
	char zuo1,zuo2;
	int izuo1,izuo2;
	cin>>c1>>pai1>>zuo1>>c2>>pai2>>zuo2;
	izuo1 = zuo1-'A'+1;
	izuo2 = zuo2-'A'+1;
	if(c1==c2) {
		cout<<1;
	}
	else cout<<0;
	
	if(c1==c2&&pai1==pai2) {
		cout<<1;
	}
	else cout<<0;
	bool b= c1==c2&&pai1==pai2&&((izuo1<=3&&izuo2<=3)||(izuo1>3&&izuo2>3));
	if(b) {
		cout<<1;
	}
	else cout<<0;
	
	if(b&&abs(izuo1-izuo2)==1){
		cout<<1;
	}
	else cout<<0;
	return 0;
} 
