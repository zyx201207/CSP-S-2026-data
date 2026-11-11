#include<bits/stdc++.h>
using namespace std;
string c1,z1,c2,z2;
int a1,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>z1>>c2>>z2;
	a1+=z1[0]-48;
	a1=a1*10+(z1[1]-48);
	a2+=z2[0]-48;
	a2=a2*10+(z2[1]-48);
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<1;
		if(a1==a2){
			cout<<1;
			if(((z1[2]=='D'||z1[2]=='F')&&(z2[2]=='D'||z2[2]=='F'))||((z1[2]>=65&&z1[2]<=67)&&(z2[2]>=65&&z2[2]<=67))){
				cout<<1;
				if(z1[2]=='D'){
					cout<<1;
				}
				else if(min(z1[2],z2[2])+1==max(z1[2],z2[2])){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
	
	
	return 0;
} 
