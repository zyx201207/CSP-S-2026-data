#include<bits/stdc++.h>
using namespace std;
bool a,b,c,d;
string n,n1,m1,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>n1>>m>>m1;
	if(n==m){
		a=1;
	}
	if(a&&n1[0]==m1[0]&&n1[1]==m1[1]){
		b=1;
	}
	if(a&&b&&((n1[2]=='F'&&m1[2]=='D')||(n1[2]=='D'&&m1[2]=='F'))){
		c=1;
	}else if(a&&b&&((n1[2]=='A'&&m1[2]=='B')||(n1[2]=='B'&&m1[2]=='A')||(n1[2]=='B'&&m1[2]=='C')||(n1[2]=='C'&&m1[2]=='B')||(n1[2]=='A'&&m1[2]=='C')||(n1[2]=='C'&&m1[2]=='A'))){
		c=1;
	}
	if(a&&b&&c&&(n1[2]+1==m1[2]||n1[2]==m1[2]+1)){
		d=1;
	}
	cout<<a<<b<<c<<d;
	
	return 0;
} 
