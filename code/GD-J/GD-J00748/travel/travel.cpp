#include<bits/stdc++.h>
using namespace std;
char p1[5],p2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool pd1,pd2,pd3,pd4;
	if(c1==c2){
		cout<<1;
		pd1=1;
	}else{
		cout<<0;
		pd1=0;
	}
	string p1,p2;
	for(int i=0;i<2;i++){
		p1[i]=s1[i];
		p2[i]=s2[i];
	}
	char z1=s1[2],z2=s2[2];
	bool is=1;
	for(int i=0;i<2;i++){
		if(p1[i]!=p2[i]){
			is=0;
		}
	}
	if(is&&pd1){
		cout<<1;
		pd2=1;
	}else{
		cout<<0;
		pd2=0;
	}
	if((z1=='A'||z1=='B'||z1=='C')&&(z2=='A'||z2=='B'||z2=='C')&&pd2){
		cout<<1;
		pd3=1;
	}else if((z1=='D'||z1=='F')&&(z2=='D'||z2=='F')&&pd2){
		cout<<1;
		pd3=1;
	}else{
		cout<<0;
		pd3=0;
	}
	if(abs(z1-z2)==1&&pd3){
		cout<<1;
		pd4=1;
	}else{
		cout<<0;
		pd4=0;
	}
	return 0;
}
