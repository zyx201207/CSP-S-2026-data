#include <bits/stdc++.h>
using namespace std;
int r1,r2,a1,a2;
string b1,b2;
bool r,p,s,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","W",stdout);
	
	cin>>a1>>b1>>a2>>b2;
	
	if(a1==a2)c=1;
	cout<<c;
	
	if(c){
		r1=int(b1[0]-48)*10+int(b1[1]-48);
		r2=int(b2[0]-48)*10+int(b2[1]-48);
		if(r1=r2) r=1;
	}
	cout<<r;
	
	if(r){
		if(b1[2]<='C' && b1[2]>='A' && b2[2]<='C' && b2[2]>='A'){
			p=1;
		}
		else if(b1[2]<='F' && b1[2]>='D' && b2[2]<='F' && b2[2]>='D'){
			p=1;
		}
	}
	cout<<p;
	
	if(p){
		if(int(abs(b1[2]-b2[2]))==1){
			s=1;
		}
	}
	cout<<s;
	return 0;
}
