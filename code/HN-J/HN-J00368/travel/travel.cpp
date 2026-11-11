#include<bits/stdc++.h> 
using namespace std;
int c1,c2;
int p1,p2;
char z1,z2; 
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>p1>>z1>>c2>>p2>>z2;
	if(c1==c2) a=1;
	else a=0;
	if(a==1){
		if(p1==p2) b=1;
	}
	else b=0;
	if(a==1&&b==1){
		if(z1=='A'||z1=='B'||z1=='C'&&z2=='A'||z2=='B'||z2=='C') c=1;
			else if(z1=='D'||z1=='F'&&z2=='D'||z2=='F')	c=1;					
	}
	else c=0;
	if(a==1&&b==1&&c==1){
		if(z1=='A'&&z2=='B'||z2=='A'&&z1=='B'||z1=='C'&&z2=='B'||z2=='C'&&z1=='B'||z1=='D'&&z2=='F'||z2=='D'&&z1=='F')	
		d=1;			
	}
	else d=0;
	cout<<a<<b<<c<<d; 
	fclose(stdin);
	fclose(stdout);
}
