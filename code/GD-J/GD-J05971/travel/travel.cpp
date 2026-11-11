#include<bits/stdc++.h>
using namespace std;
int x1,x2;
string z1,z2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>z1>>x2>>z2;
	int h1=0,h2=0,l1,l2;
	h1=z1[0]*10+z1[1]*1;
	h2=z2[0]*10+z2[1]*1;
	if(z1[2]=='A'){l1=1;}
	if(z1[2]=='B'){l1=2;}
	if(z1[2]=='C'){l1=3;}
	if(z1[2]=='D'){l1=5;}
	if(z1[2]=='F'){l1=6;}
	if(z2[2]=='A'){l2=1;}
	if(z2[2]=='B'){l2=2;}
	if(z2[2]=='C'){l2=3;}
	if(z2[2]=='D'){l2=5;}
	if(z2[2]=='F'){l2=6;}
	if(x1==x2){
		if(h1==h2){
			if((l1<=5&&l2<=5)||(l1>=5&&l2>=5)){
				if((l1-l2)==1||(l1-l2)==-1){
					cout<<1111;
				}else{
					cout<<1110;
				}
			}else{
				cout<<1100;
			}
		}else{
			cout<<1000;
		}
	}else{
		cout<<0000;
	}
	return 0;
}
