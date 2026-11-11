//GZ-J00146 北师大贵阳附中 赵泊宁 
#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string z1,z2,z3,z4;
bool a=0,b=0,c=0,d=0;
int main(){
	freopen("traval.in","r",stdin);
	freopen("traval.out","w",stdout);
	cin>>c1>>z1>>c2>>z2;
	if(c1==c2){
		a=1;
		for(int i=0;i<=1;i++){
		z3[i]=z1[i];
		z4[i]=z2[i];
		}
	z3[2]=z1[2];
	z4[2]=z2[2];
	if(z3[0]==z4[0]&&z3[1]==z4[1]){
		b=1;
		char e=z3[2],f=z4[2];
		if(e=='A'){
			if(f=='B'||f=='C'){
				c=1;
				if(f=='B'){
					d=1;
				}
			}
			
			}
		if(e=='B'){
			if(f=='A'||f=='C'){
				c=1;
				d=1;
			}
		}
			if(e=='C'){
			if(f=='A'||f=='B'){
				c=1;
				if(f=='B'){
					d=1;
				}
				}
			}
			if(e=='D'){
				if(f=='E'){
				c=1;
					d=1;
			}
		}
			if(e=='E'){
				if(f=='D'){
				c=1;
					d=1;
			}
		}
	}
}
	cout<<a<<b<<c<<d<<endl;
	return 0;
}
