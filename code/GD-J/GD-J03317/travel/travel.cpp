#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n1,n2,z3,z4;
	string z1,z2;
	cin>>n1>>z1>>n2>>z2;
	z3=z1[0]-'0'*10+z1[1];
	z4=z2[0]-'0'*10+z2[1];
	if(n1==n2){
		if(z3==z4){
			cout<<1;
			if((z1[2]!='D'&&z1[2]!='F')&&(z2[2]!='D'&&z2[2]!='F')) {
				cout<<1;
				if(z1[2]=='B'||z2[2]=='B'){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else {
				cout<<0<<0;
				if((z1[2]=='D'||z1[2]=='F')&&(z2[2]=='D'||z2[2]=='F'))
					cout<<1<<1;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
}
