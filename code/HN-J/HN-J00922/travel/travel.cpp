#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2){
		cout<<1;
		if(b1[0]==b2[0]&&b2[1]==b1[1]){
			cout<<1;
			if((b1[2]>='A'&&b1[2]<='C'&&b2[2]>='A'&&b2[2]<='C')||(b1[2]>='D'&&b1[2]<='E'&&b2[2]>='D'&&b2[2]<='E')){
				cout<<1;
				if(char(b1[2]+1)==b2[2]||char(b1[2]-1)==b2[2])cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
}
