#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	int a=a2[0]-'0';
	a*=10;
	a+=a2[1]-'0';
	int b=b2[0]-'0';
	b*=10;
	b+=b2[1]-'0';
	if(a1[0]==b1[0] && a1[1]==b1[1]){
		cout<<1;
		if(a==b){
			cout<<1;
			if(a2[2]>='A' && a2[2]<='C' && b2[2]>='A' && b2[2]<='C'){
				cout<<1;
				if(a2[2]=='C' && b2[2]=='A') cout<<0;
				else if(b2[2]=='C' && a2[2]=='A') cout<<0;
				else cout<<1;
			}
			else if(a2[2]>='D' && a2[2]<='F' && b2[2]>='D' && b2[2]<='F') cout<<1;
			else cout<<"00";
	  	}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
