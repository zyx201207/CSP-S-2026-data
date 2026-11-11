#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int c1i=0,s1i=0,c2i=0,s2i=0,z1i=0,z2i=0;
	char z1=s1[2],z2=s2[2];
	for(int i=0;i<2;i++){
		c1i=c1i*10+(c1[i]-'0');
		s1i=s1i*10+(s1[i]-'0');
		c2i=c2i*10+(c2[i]-'0');
		s2i=s2i*10+(s2[i]-'0');
	}
	if(c1i==c2i){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s2i==s1i) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(z1=='A' || z1=='B' || z1=='C'){
		z1i=1;
	}
	else{
		z1i=2;
	}
	if(z2=='A' || z2=='B' || z2=='C'){
		z2i=1;
	}
	else{
		z2i=2;
	}
	if(z1i==z2i) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(z1=='A'){
		if(z2==z1+1) cout<<1;
		else cout<<0;
	}
	else if(z1=='B'){
		if(z2==z1+1 || z2==z1-1) cout<<1;
		else cout<<0;
	}
	else if(z1=='C'){
		if(z2==z1-1) cout<<1;
		else cout<<0;
	}
	else if(z1=='D'){
		if(z2=='E') cout<<1;
		else cout<<0;
	}
	else if(z1=='E'){
		if(z2=='D') cout<<1;
		else cout<<0;
	}
	return 0;
}
