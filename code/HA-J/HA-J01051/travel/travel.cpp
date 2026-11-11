#include<bits/stdc++.h>
using namespace std;
int a=0,b=0,c=0,d=0,n=0,m=0;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	int ant=0,ant1=0;
	for(int i=0; i<3; i++) {
		if(s1[i]!=s2[i]) ant1=1;
	}
	if(ant1==0) {
		cout<<"0000";
		return 0;
	}
	for(int i=0; i<2; i++) {
		if(c1[i]==c2[i]) ant++;
	}
	if(ant==2) a=1;
	for(int i=0; i<=1; i++) {
		n=s1[i]+n*10;
		m=s2[i]+m*10;
	}

	if(n==m) {
		if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F') {
			b=1;
			c=1;
		} else {
			b=1;
		}
	}
	if(n==m&&s2[2]-s1[2]==1&&s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F') {
		d=1;
	}
	cout<<a<<b<<c<<d;


	return 0;
}
