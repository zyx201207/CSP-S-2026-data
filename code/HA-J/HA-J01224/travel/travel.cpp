#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int s=0;
	char p;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else {p='0'; cout<<p;}
	if(p!='0'){
	for(int i=0;i<2;i++){
		if(b[i]==d[i]) s++;
	}
	if(s==2) cout<<1;
	else {p='0'; cout<<p;}}
	else{p='0'; cout<<p;}
	if(p!='0'){
	if (b[2]=='D'&&d[2]=='F') cout<<1;
	else if (d[2]=='D'&&b[2]=='F') cout<<1;
	else if (d[2]=='A'&&b[2]=='B') cout<<1;
	else if (d[2]=='A'&&b[2]=='C') cout<<1;
	else if (d[2]=='B'&&b[2]=='A') cout<<1;
	else if (d[2]=='B'&&b[2]=='C') cout<<1;
	else if (d[2]=='C'&&b[2]=='A') cout<<1;
	else if (d[2]=='C'&&b[2]=='B') cout<<1;
	else {p='0'; cout<<p;}}
	else {p='0'; cout<<p;}
	if(p!='0'){
	if(b[2]=='D'&&d[2]=='F') cout<<1;
	else if (d[2]=='D'&&b[2]=='F') cout<<1;
	else if (d[2]=='A'&&b[2]=='B') cout<<1;
	else if (d[2]=='B'&&b[2]=='A') cout<<1;
	else if (d[2]=='B'&&b[2]=='C') cout<<1;
	else if (d[2]=='C'&&b[2]=='B') cout<<1;
	else {p='0'; cout<<p;}}
	else {p='0'; cout<<p;}
	return 0;
	}
	
