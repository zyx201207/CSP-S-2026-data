#include <bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
bool f[4];
int pd(char x,char y){
	if (x=='A'){
		if (y=='B') return 2;
		else if (y=='C') return 1;
	}if (x=='B'){
		if (y=='A'||y=='C') return 2;
	}if (x=='C'){
		if (y=='B') return 2;
		else if (y=='A') return 1;
	}
	else if (x=='D'){
		if (y=='F') return 2;
	}else if (x=='F'){
		if (y=='D') return 2;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if (a==c) f[0]=1;
	if (a==c&&b[0]==d[0]&&b[1]==d[1]) f[1]=1;
	if (a==c&&b[0]==d[0]&&b[1]==d[1]&&pd(b[2],d[2])>=1) f[2]=1;
	if (a==c&&b[0]==d[0]&&b[1]==d[1]&&pd(b[2],d[2])==2) f[3]=1;
	for (int i=0;i<4;i++) cout<<f[i];
	cout<<'\n';
	return 0;
} 
