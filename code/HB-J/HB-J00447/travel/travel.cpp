#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string h1,h2,z1,z2;
	int cnt=0;
	cin>>h1>>z1>>h2>>z2;
	if(h1==h2)cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	
	
	if(z1[0]+z1[1]==z2[0]+z2[1])cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	
	if(z1[2]>='A'&&z1[2]<='C')cnt++;
	if(z2[2]>='A'&&z2[2]<='C')cnt++;
	if(cnt!=1)cout<<1;
	else cout<<0;
	if(abs(z1[2]-z2[2])==1){
		if(!(z1[2]=='C'&&z2[2]=='D')){
			if(!(z1[2]=='D'&&z2[2]=='C')){
				cout<<1;
				return 0;
			}
		}
	}
	cout<<0;
	return 0;
}
